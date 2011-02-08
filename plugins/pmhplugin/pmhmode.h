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
 *       NAME <MAIL@ADRESS>                                                *
 ***************************************************************************/
#ifndef PMHMODE_H
#define PMHMODE_H

#include <coreplugin/modemanager/basemode.h>

#include <QObject>
class QModelIndex;

namespace PMH {
namespace Internal {
namespace Ui {
class PmhMode;
}

class PmhMode : public Core::BaseMode
{
    Q_OBJECT
public:
    explicit PmhMode(QObject *parent = 0);
    ~PmhMode();

private Q_SLOTS:
    void on_addButton_clicked();
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::PmhMode *ui;
    QWidget *m_Widget;
};

}  // End namespace Internal
}  // End namespace PMH

#endif // PMHMODE_H

