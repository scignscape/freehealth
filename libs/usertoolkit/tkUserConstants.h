/***************************************************************************
 *   FreeMedicalForms                                                      *
 *   Copyright (C) 2008-2009 by Eric MAEKER                                *
 *   eric.maeker@free.fr                                                   *
 *   All rights reserved.                                                  *
 *                                                                         *
 *   This program is a free and open source software.                      *
 *   It is released under the terms of the new BSD License.                *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *   modification, are permitted provided that the following conditions    *
 *   are met:                                                              *
 *   - Redistributions of source code must retain the above copyright      *
 *   notice, this list of conditions and the following disclaimer.         *
 *   - Redistributions in binary form must reproduce the above copyright   *
 *   notice, this list of conditions and the following disclaimer in the   *
 *   documentation and/or other materials provided with the distribution.  *
 *   - Neither the name of the FreeMedForms' organization nor the names of *
 *   its contributors may be used to endorse or promote products derived   *
 *   from this software without specific prior written permission.         *
 *                                                                         *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
 *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
 *   COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *
 *   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
 *   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN     *
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
 *   POSSIBILITY OF SUCH DAMAGE.                                           *
 ***************************************************************************/
/***************************************************************************
 *   Main Developper : Eric MAEKER, <eric.maeker@free.fr>                  *
 *   Contributors :                                                        *
 *       NAME <MAIL@ADRESS>                                                *
 ***************************************************************************/
#ifndef TKUSERCONSTANTS_H
#define TKUSERCONSTANTS_H

#include <QFlags>

/**
 \brief all constants used by the usertoolkit objects and widgets.
 \ingroup usertoolkit constants_usertoolkit
  \ingroup usermanager
*/
namespace tkUserConstants
{
    // User Database connection
    const char * const USER_DB_CONNECTION           = "users";

    // constants for DATAS table represent DATANAME field
    const char * const USER_DATAS_TITLE             = "identity.title";
    const char * const USER_DATAS_GENDER            = "identity.gender";
    const char * const USER_DATAS_ADRESS            = "identity.adress";
    const char * const USER_DATAS_ZIPCODE           = "identity.zip";
    const char * const USER_DATAS_CITY              = "identity.city";
    const char * const USER_DATAS_COUNTRY           = "identity.country";
    const char * const USER_DATAS_TEL1              = "identity.tel1";
    const char * const USER_DATAS_TEL2              = "identity.tel2";
    const char * const USER_DATAS_TEL3              = "identity.tel3";
    const char * const USER_DATAS_FAX               = "identity.fax";
    const char * const USER_DATAS_PRACTIDENTIFIANT  = "identity.identifiant";
    const char * const USER_DATAS_SPECIALTY         = "identity.specialty";
    const char * const USER_DATAS_QUALIFICATION     = "identity.qualification";
    const char * const USER_DATAS_PREFERENCES       = "pref";
    const char * const USER_DATAS_LOGINHISTORY      = "loginHistory";


    const char* const  PAPERS_MARK                     = "papers";                  /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_GENERICHEADER        = "papers.generic.header";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_GENERICFOOTER        = "papers.generic.footer";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_GENERICWATERMARK     = "papers.generic.watermark";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_ADMINISTRATIVEHEADER = "papers.admin.header";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_ADMINISTRATIVEFOOTER = "papers.admin.footer";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_ADMINISTRATIVEWATERMARK = "papers.admin.watermark";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_PRESCRIPTIONHEADER   = "papers.prescription.header";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_PRESCRIPTIONFOOTER   = "papers.prescription.footer";   /** \brief x \sa tkUser::setDynamicDataValue() */
    const char * const USER_DATAS_PRESCRIPTIONWATERMARK= "papers.prescription.watermark";   /** \brief x \sa tkUser::setDynamicDataValue() */

//    const char * const USER_ROLE_SUPERADMIN      = "role.superadmin";
    // if you add or delete a role, you must change tkUserRightsWidget
    const char * const USER_ROLE_USERMANAGER     = "role.userManager";
    const char * const USER_ROLE_MEDICAL         = "role.medical";
    const char * const USER_ROLE_DOSAGES         = "role.dosage";
    const char * const USER_ROLE_PARAMEDICAL     = "role.paramedical";
    const char * const USER_ROLE_ADMINISTRATIVE  = "role.administrative";

    const char * const DEFAULT_USER_UUID      = "{bff46aaa-5fed-481a-8af3-d5985c549e9c}";
    const char * const DEFAULT_USER_LOGIN     = "YWRtaW4=";                      // admin
    const char * const DEFAULT_USER_PASSWORD  = "0DPiKuNIrrVmD8IUCuw1hQxNqZc=";  // admin
    const char * const DEFAULT_USER_NAME      = "GENERAL ADMINISTRATOR";
    const char * const DEFAULT_USER_SURNAME   = "THIS A GENERIC USER";
    const char * const DEFAULT_USER_ADRESS    = "You should change the login/password of this user.";

    const char * const DEFAULT_USER_ROLE      = USER_ROLE_USERMANAGER;
    int const          DEFAULT_USER_RIGHT     = -1;
    const char * const DEFAULT_USER_SPECIALTY = "Default Super Administrator";
    const char * const DEFAULT_USER_HEADER    =
            "<html><body>" \
            "<table width=100% border=2>" \
            "<tr>" \
            " <td>This is simple sample of what</td>" \
            " <td>&nbsp;</td>" \
            " <td>you can do with this software</td>" \
            "</tr>" \
            "<tr>" \
            " <td>[:identity.title] [:identity.fullname] adds your recorded title then your name</td>" \
            " <td>&nbsp;</td>" \
            " <td>&nbsp;</td>" \
            "</tr>" \
            "<tr>" \
            " <td>[:identity.identifiant] adds your recorded ids</td>" \
            " <td>&nbsp;</td>" \
            " <td>&nbsp;</td>" \
            "</tr>" \
            "<tr>" \
            " <td>[:identity.specialty] adds your recorded specialties<br>" \
            "     [:identity.qualification] adds your recorded qualifications</td>" \
            " <td>&nbsp;</td>" \
            " <td>&nbsp;</td>" \
            "</tr>" \
            "</table>"  \
            "</body></html>";
    const char * const DEFAULT_USER_FOOTER   =
            "<html><body>"  \
            "Here you can add urgencies phone numbers<br>"  \
            "Or What ever you want."  \
            "</body></html>";


    // For database management
    /** \brief Enumerates all the tables of the users' database */
    enum Tables
    {
        Table_USERS=0, Table_DATAS, Table_RIGHTS,
        Table_MaxParam
    };

    /** \brief Enumerates the fields of the table USERS */
    enum USER_FIELDS
    {
        USER_ID = 0,
        USER_UUID, USER_VALIDITY,
        USER_LOGIN, USER_PASSWORD, USER_LASTLOG,
        USER_NAME, USER_SECONDNAME, USER_SURNAME,
        USER_MAIL, USER_LANGUAGE, USER_LOCKER,
        USER_MaxParam
    };

    /** \brief Enumerates the fields of the table USERS_DATAS */
    enum DATASfields
    {
        DATAS_ID = 0 , DATAS_USER_UUID,
        DATAS_DATANAME, DATAS_STRING, DATAS_LONGSTRING, DATAS_FILE, DATAS_NUMERIC, DATAS_DATE,
        DATAS_LANGUAGE, DATAS_LASTCHANGE, DATAS_TRACE_ID,
        DATAS_MaxParam
    };

    /** \brief Enumerates the fields of the table USERS_RIGHTS */
    enum RIGHTSfields  // 1 USER --> N RIGHTS defined by role
    {
        // Rights
        RIGHTS_ID=0,
        RIGHTS_USER_UUID,
        RIGHTS_ROLE, RIGHTS_RIGHTS,
        RIGHTS_MaxParam
    };

}

/**
  \brief Contains the generic enumeration to use with the tkUserModel.
  \ingroup usertoolkit constants_usertoolkit
  \ingroup usermanager
*/
namespace User
{
    // For complete abstraction of database, use the tkUserModel with this abstracting enum
    enum UserModel {
        // ORDER SHOULD NEVER CHANGE
        UserId = 0,
        UserUuid,           /*!< \brief Unique identifier the each users */
        UserValidity,       /*!< \brief Validity of this user */
        UserLogin,          /*!< \brief Crypted login \sa tkUserGlobal::loginForSQL() */
        UserPassword,       /*!< \brief Crypted password \sa tkUserGlobal::crypt() */
        UserLastLogin,      /*!< \brief Date of the last correct login */
        UserName,           /*!< \brief Name */
        UserSecondName,     /*!< \brief Second name */
        UserSurname,        /*!< \brief surname */
        UserMail,           /*!< \brief Mail address */
        UserLanguage,       /*!< \brief Language for interface */
        UserLocker,         /*!< \brief Locker */
        UserLanguageIndex,  /*!< \brief Language index from tkTranslator::availbleLanguages() */
        // ORDER CAN CHANGE
        UserGenderIndex, UserTitleIndex, UserGender, UserTitle,
        UserAdress, UserZipcode, UserCity, UserCountry, UserTel1, UserTel2, UserTel3, UserFax, UserPractitionerId,
        UserSpecialities, UserQualifications, UserPreferences,

        UserGenericHeader,            /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserGenericFooter,            /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserGenericWatermark,         /*!< \brief Extra Document \sa tkTextDocumentExtra */

        UserAdministrativeHeader,     /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserAdministrativeFooter,     /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserAdministrativeWatermark,  /*!< \brief Extra Document \sa tkTextDocumentExtra */

        UserPrescriptionHeader,       /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserPrescriptionFooter,       /*!< \brief Extra Document \sa tkTextDocumentExtra */
        UserPrescriptionWatermark,    /*!< \brief Extra Document \sa tkTextDocumentExtra */

        UserManagerRights,
        UserDrugsRights,
        UserMedicalRights,
        UserParamedicalRights,
        UserAdministrativeRights,

        UserDecryptedLogin,
        UserLoginHistory,
        UserIsModified,
        UserWarn,                   // for debugging function only with data()
        UserWarnText,
        UserMaxParam
    };

    // for Rights understanding
    // if you add or delete a right, you must change tkUserRightsWidget
    enum UserRight
    {
        NoRights       = 0x00000000,
        ReadOwn        = 0x00000001,
        ReadDelegates  = 0x00000002,
        ReadAll        = 0x00000004,
        WriteOwn       = 0x00000010,
        WriteDelegates = 0x00000020,
        WriteAll       = 0x00000040,
        Print          = 0x00000100,
        Create         = 0x00000200,
        Delete         = 0x00000400
    };
    Q_DECLARE_FLAGS(UserRights, UserRight)

}
Q_DECLARE_OPERATORS_FOR_FLAGS(User::UserRights)
#endif // TKUSERCONSTANTS_H
