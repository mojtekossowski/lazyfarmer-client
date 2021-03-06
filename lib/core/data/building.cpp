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

#include "building.h"
#include "player.h"
#include "configreader.h"

#include <QtCore/QTimer>

using namespace Core;
using namespace Core::Data;

Building::Building(Player *parent)
    : IPlayerData(parent)
    , m_id(0)

    , m_type(BuildingType::Unknown)

    , m_farmId(0)
    , m_position(0)

    , m_level(0)
    , m_animals(0)
    , m_remaining(0)
{
    initializeConnections();
}

void Building::update(const QVariant &info)
{
    const QVariantMap buildingInfo = info.toMap();

    int id = buildingInfo["Id"].toInt();
    int farmId = buildingInfo["FarmId"].toInt();
    int position = buildingInfo["Position"].toInt();
    int level = buildingInfo["Level"].toInt();
    int animals = buildingInfo["Animals"].toInt();
    int remaining = buildingInfo["Remaining"].toInt();

    if (m_id != id
        || m_farmId != farmId
        || m_position != position
        || m_level != level
        || m_animals != animals
        || m_remaining != remaining)
    {
        m_id = id;

        // Lazy-load for BuildingDetails object
        BuildingType type = ConfigReader::instance().buildingType(id);
        if (m_type != type) {
            m_type = type;
            m_buildingData = BuildingData::create(m_owner, type);
        }

        m_farmId = farmId;
        m_position = position;
        m_level = level;
        m_animals = animals;

        m_remaining = remaining;
        m_doneTimestamp = (remaining <= 0)
                ? QDateTime()
                : QDateTime::currentDateTime().addSecs(remaining);

        m_name = buildingName(id);

        emit buildingChanged();
        emit fetchBuildingRequested(details(), m_type);

    }

    IPlayerData::update(info);
}

void Building::updateBuildingData(const QVariant &info)
{
    if (m_buildingData) {
        m_buildingData->update(info);
    }
}

QString Building::toString() const
{
    return QString("Building: %1 (id:%2 <%3>) (%4, %5) Level: %6 Remaining: %7")
            .arg(m_name)
            .arg(m_id)
            .arg(BuildingHelper::toString(m_type))
            .arg(m_farmId)
            .arg(m_position)
            .arg(m_level)
            .arg(m_remaining);
}

void Building::initializeConnections() const
{
    connect(this,       &Building::fetchBuildingRequested,
            m_owner,    &Player::updateBuildingRequested);
}
