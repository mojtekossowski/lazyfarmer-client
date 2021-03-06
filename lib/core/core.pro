# This file is part of the LazyFarmer project.
# Copyright 2017 Wojciech Ossowski <w.j.ossowski@gmail.com>.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

QT       += core network gui qml
CONFIG   += c++14 dll

TARGET = CoreLib
TEMPLATE = lib

INCLUDEPATH += $${PWD}/extractors
INCLUDEPATH += $${PWD}/data

SOURCES += \
        $${PWD}/api/*.cpp \
        $${PWD}/api/messages/*.cpp \
        $${PWD}/data/*.cpp  \
        $${PWD}/extractors/*.cpp \
        $${PWD}/model/*.cpp \
        $${PWD}/*.cpp

HEADERS += \
        $${PWD}/api/*.h \
        $${PWD}/api/messages/*.h \
        $${PWD}/data/*.h \
        $${PWD}/extractors/*.h \
        $${PWD}/model/*.h \
        $${PWD}/*.h

include($${PWD}/../../common.pri)
