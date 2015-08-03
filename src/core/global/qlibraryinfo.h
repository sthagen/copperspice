/***********************************************************************
*
* Copyright (c) 2012-2015 Barbara Geller
* Copyright (c) 2012-2015 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see 
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#ifndef QLIBRARYINFO_H
#define QLIBRARYINFO_H

#include <QtCore/qstring.h>
#include <QtCore/QDate>
#include <qsettings.h>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_SETTINGS

class Q_CORE_EXPORT QLibraryInfo
{
 public:
   static QString licensee();
   static QString licensedProducts();
   static QString buildKey();

#ifndef QT_NO_DATESTRING
   static QDate buildDate();
#endif

   enum LibraryLocation {
      PluginsPath,
      ImportsPath,
      Qml2ImportsPath,
      TranslationsPath,
      SettingsPath,
   };
   static QString location(LibraryLocation);

 private:
   QLibraryInfo();

   static QSettings *configuration();
   static QSettings *findConfiguration();
   static QSettings *qt_library_settings();
};

#endif /* QT_NO_SETTINGS */

Q_CORE_EXPORT void cs_print_build_info();

QT_END_NAMESPACE

#endif