/**
 ** This file is part of the LazyFarmer project.
 ** Copyright 2017 Wojciech Ossowski <w.j.ossowski@gmail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as
 ** published by the Free Software Foundation, either version 3 of the
 ** License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "getfarminfo.h"
#include "../apigateway.h"

#include "extractors/playerinfoextractor.h"

#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

#include <QtNetwork/QNetworkRequest>

using namespace Core;
using namespace Core::Api;
using namespace Core::Api::Messages;
using namespace Core::Extractors;

const QUrl GetFarmInfo::url() const
{
    return m_gateway->buildEndpointAjaxUrl("farm", {
        { "mode", "getfarms" }
    });
}

void GetFarmInfo::handleResponse(QNetworkReply *reply)
{
    const auto contents = reply->readAll();

    m_gateway->handlePlayerData(contents);

    emit this->finished();
}
