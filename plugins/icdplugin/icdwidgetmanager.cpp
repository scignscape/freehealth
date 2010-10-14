/***************************************************************************
 *  The FreeMedForms project is a set of free, open source medical         *
 *  applications.                                                          *
 *  (C) 2008-2010 by Eric MAEKER, MD (France) <eric.maeker@free.fr>        *
 *  All rights reserved.                                                   *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program (COPYING.FREEMEDFORMS file).                   *
 *  If not, see <http://www.gnu.org/licenses/>.                            *
 ***************************************************************************/
/***************************************************************************
 *   Main Developper : Eric MAEKER, <eric.maeker@free.fr>                  *
 *   Contributors :                                                        *
 *       NAME <MAIL@ADRESS>                                                *
 ***************************************************************************/
#include "icdwidgetmanager.h"
#include "constants.h"
#include "icddownloader.h"

#include <utils/log.h>
#include <utils/global.h>
#include <translationutils/constanttranslations.h>

#include <coreplugin/constants_icons.h>
#include <coreplugin/constants_menus.h>
#include <coreplugin/icore.h>
#include <coreplugin/isettings.h>
#include <coreplugin/itheme.h>
#include <coreplugin/contextmanager/contextmanager.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/uniqueidmanager.h>

#include <QGridLayout>
#include <QDialog>
#include <QTreeWidget>
#include <QHeaderView>

using namespace ICD;
using namespace Internal;
using namespace Trans::ConstantTranslations;

inline static Core::ActionManager *actionManager() {return Core::ICore::instance()->actionManager();}
static inline Core::ContextManager *contextManager() { return Core::ICore::instance()->contextManager(); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////      MANAGER      ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
IcdWidgetManager *IcdWidgetManager::m_Instance = 0;

IcdWidgetManager *IcdWidgetManager::instance()
{
    if (!m_Instance)
        m_Instance = new IcdWidgetManager(qApp);
    return m_Instance;
}

IcdWidgetManager::IcdWidgetManager(QObject *parent) : IcdActionHandler(parent)
{
    connect(Core::ICore::instance()->contextManager(), SIGNAL(contextChanged(Core::IContext*)),
            this, SLOT(updateContext(Core::IContext*)));
    setObjectName("IcdWidgetManager");
    Utils::Log::addMessage(this, "Instance created");
}

void IcdWidgetManager::updateContext(Core::IContext *object)
{
    IcdContextualWidget *view = 0;
    do {
        if (!object) {
            if (!m_CurrentView)
                return;

            //            m_CurrentView = 0;  // keep trace of the last active view (we need it in dialogs)
            break;
        }
        view = qobject_cast<IcdContextualWidget *>(object->widget());
        if (!view) {
            if (!m_CurrentView)
                return;

            //            m_CurrentView = 0;   // keep trace of the last active view (we need it in dialogs)
            break;
        }

        if (view == m_CurrentView) {
            return;
        }

    } while (false);
    if (view) {
        IcdActionHandler::setCurrentView(view);
    }
}

IcdContextualWidget *IcdWidgetManager::currentView() const
{
    return IcdActionHandler::m_CurrentView;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////  ACTION HANDLER   ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
IcdActionHandler::IcdActionHandler(QObject *parent) :
        QObject(parent),
        aRecreateDatabase(0),
        aShowDatabaseInformations(0),
        m_CurrentView(0)
{
    setObjectName("IcdActionHandler");
    Utils::Log::addMessage(this, "Instance created");

    Core::UniqueIDManager *uid = Core::ICore::instance()->uniqueIDManager();
    Core::ITheme *th = Core::ICore::instance()->theme();

    QAction *a = 0;
    Core::Command *cmd = 0;
    QList<int> ctx = QList<int>() << uid->uniqueIdentifier(ICD::Constants::C_ICD_PLUGINS);
    QList<int> globalcontext = QList<int>() << Core::Constants::C_GLOBAL_ID;

//    Core::ActionContainer *menu = actionManager()->actionContainer(Constants::M_PLUGINS_ICD);
//    if (!menu) {
//        menu = actionManager()->createMenu(DrugsWidget::Constants::M_PLUGINS_ICD);
//        menu->appendGroup(DrugsWidget::Constants::G_PLUGINS_VIEWS);
//        menu->setTranslations(DrugsWidget::Constants::DRUGSMENU_TEXT);
//    }
//    Q_ASSERT(menu);
//#ifdef FREEDIAMS
//    actionManager()->actionContainer(Core::Constants::MENUBAR)->addMenu(menu, DrugsWidget::Constants::G_PLUGINS_DRUGS);
//#else
//    actionManager()->actionContainer(Core::Constants::M_PLUGINS)->addMenu(menu, Core::Constants::G_PLUGINS_DRUGS);
//#endif

    // Create local actions
    Core::ActionContainer *hmenu = actionManager()->actionContainer(Core::Constants::M_HELP_DATABASES);
    a = aRecreateDatabase = new QAction(this);
    a->setObjectName("aRecreateDatabase");
    cmd = actionManager()->registerAction(a, Constants::A_RECREATE_ICD_DB, ctx);
    cmd->setTranslations(Constants::RECREATE_DATABASE_TEXT, Constants::RECREATE_DATABASE_TEXT, Constants::ICDCONSTANTS_TR_CONTEXT);
    hmenu->addAction(cmd, Core::Constants::G_HELP_DATABASES);
    connect(a, SIGNAL(triggered()), this, SLOT(recreateDatabase()));


    // Databases informations
    a = aShowDatabaseInformations = new QAction(this);
    a->setIcon(th->icon(Core::Constants::ICONHELP));
    cmd = actionManager()->registerAction(a, Constants::A_DATABASE_INFOS, QList<int>() << Core::Constants::C_GLOBAL_ID);
    cmd->setTranslations(Constants::DATABASE_INFOS_TEXT, Constants::DATABASE_INFOS_TEXT, Constants::ICDCONSTANTS_TR_CONTEXT);
    cmd->retranslate();
    hmenu->addAction(cmd, Core::Constants::G_HELP_DATABASES);
    connect(aShowDatabaseInformations,SIGNAL(triggered()), this, SLOT(showDatabaseInformations()));


    contextManager()->updateContext();
    actionManager()->retranslateMenusAndActions();
}

void IcdActionHandler::setCurrentView(IcdContextualWidget *view)
{
    Q_ASSERT(view);
    if (!view) { // this should never be the case
        Utils::Log::addError(this, "setCurrentView : no view", __FILE__, __LINE__);
        return;
    }
    //    qWarning() << "IcdActionHandler::setCurrentView(IcdContextualWidget *view)";

    // disconnect old view
    if (m_CurrentView) {
        if (view == m_CurrentView.data())
            return;
//        m_CurrentView->disconnect();
//        disconnect(m_CurrentView->prescriptionListView()->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
//                   this, SLOT(listViewItemChanged()));
//        disconnect(m_CurrentView->currentDrugsModel(), SIGNAL(numberOfRowsChanged()),
//                   this, SLOT(drugsModelChanged()));
//        m_CurrentView->drugSelector()->disconnectFilter();
    }
    m_CurrentView = view;

    // reconnect some actions
//    m_CurrentView->createConnections();
//    connect(m_CurrentView->prescriptionListView()->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
//            this, SLOT(listViewItemChanged()));
//    connect(m_CurrentView->currentDrugsModel(), SIGNAL(numberOfRowsChanged()),
//            this, SLOT(drugsModelChanged()));
//    m_CurrentView->drugSelector()->connectFilter();
    updateActions();
}

void IcdActionHandler::updateActions()
{
}

void IcdActionHandler::recreateDatabase()
{
    if (!m_Downloader)
        m_Downloader = new IcdDownloader(this);
    m_Downloader->createDatabase();
    connect(m_Downloader, SIGNAL(processEnded()), m_Downloader, SLOT(deleteLater()));
}

void IcdActionHandler::showDatabaseInformations()
{
    QDialog dlg(qApp->activeWindow(), Qt::Window | Qt::CustomizeWindowHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
    QGridLayout lay(&dlg);
    QTreeWidget tree(&dlg);
    tree.setColumnCount(2);
    tree.header()->hide();

    lay.addWidget(&tree);
    Utils::resizeAndCenter(&dlg);
    dlg.exec();
}

