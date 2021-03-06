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

COMPANY_NAME = "WololoPl"

DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += "CURRENT_VERSION=\\\"$${VERSION}\\\""
DEFINES += "APPLICATION_NAME=\\\"$${TARGET}\\\""
DEFINES += "COMPANY_NAME=\\\"$${COMPANY_NAME}\\\""
DEFINES += "FUNCTION_NAME=__FUNCTION__"

CONFIG(debug, debug|release) {
    DEFINES += DEBUG_MODE
    DEFINES += "ASSETS_DIRECTORY=\\\"$${PWD}/assets\\\""
} CONFIG(release, debug|release) {
    message("doopa")
}

win32 {
    QMAKE_TARGET_COMPANY = $${COMPANY_NAME}
}
