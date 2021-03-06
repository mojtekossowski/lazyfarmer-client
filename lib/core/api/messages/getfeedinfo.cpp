/**
 ** This file is part of the LazyFarmer project.
 ** Copyright 2018 Wojciech Ossowski <w.j.ossowski@gmail.com>.
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

#include "getfeedinfo.h"
#include "../apigateway.h"
#include "extractors/feedinfoextractor.h"

#include <QtCore/QVariantMap>
#include <QtCore/QJsonDocument>

using namespace Core;
using namespace Core::Api;
using namespace Core::Api::Messages;
using namespace Core::Extractors;

GetFeedInfo::GetFeedInfo(ApiGateway *gateway,
                         const Data::BuildingDetails &buildingData)
    : ApiMessage(gateway, MessageType::GetFeedInfo),
      m_buildingData(buildingData)
{

}

const QUrl GetFeedInfo::url() const
{
    return m_gateway->buildEndpointAjaxUrl("farm", {
        { "mode", "inner_init" },
        { "farm", QString::number(m_buildingData.farmId) },
        { "position", QString::number(m_buildingData.positionId) }
    });
}

void GetFeedInfo::handleResponse(QNetworkReply *reply)
{
    FeedInfoExtractor extractor(&*m_gateway->gameData());
    extractor.extract(reply->readAll());

    m_gateway->handleBuildingUpdate(m_buildingData.farmId,
                                    m_buildingData.positionId,
                                    extractor.result());

    emit finished();
}

