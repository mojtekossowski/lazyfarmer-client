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

#pragma once

#include "common.h"
#include "iplayerdata.h"
#include "buildingdata.h"

#include <QtCore/QVariantMap>
#include <QtCore/QDateTime>

namespace Core {

    class Player;

    namespace Data {

        class Building : public IPlayerData
        {
            Q_OBJECT

            Q_PROPERTY(int id                       MEMBER m_id             NOTIFY buildingChanged)
            Q_PROPERTY(BuildingType type            MEMBER m_type           NOTIFY buildingChanged)

            Q_PROPERTY(int farm                     MEMBER m_farmId         NOTIFY buildingChanged)
            Q_PROPERTY(int position                 MEMBER m_position       NOTIFY buildingChanged)
            Q_PROPERTY(int level                    MEMBER m_level          NOTIFY buildingChanged)
            Q_PROPERTY(int animals                  MEMBER m_animals        NOTIFY buildingChanged)
            Q_PROPERTY(int remaining                MEMBER m_remaining      NOTIFY buildingChanged)

            Q_PROPERTY(QDateTime doneTimestamp      MEMBER m_doneTimestamp  NOTIFY buildingChanged)
            Q_PROPERTY(int baseTimeout              READ   baseTimeout      NOTIFY buildingChanged)

            Q_PROPERTY(QString name                 MEMBER m_name           NOTIFY buildingChanged)

        public:
            using Ptr = QSharedPointer<Building>;

            explicit Building(Player *parent = nullptr);
            ~Building() override = default;

            int id() const { return m_id; }
            BuildingType type() const { return m_type; }
            int farmId() const { return m_farmId; }
            int position() const { return m_position; }
            int level() const { return m_level; }
            int animals() const { return m_animals; }
            int remaining() const { return m_remaining; }

            QDateTime doneTimestamp() const { return m_doneTimestamp; }
            int baseTimeout() const { return (m_buildingData) ? m_buildingData->totalTime() : -1; }

            QString name() const { return m_name; }

            bool isSetUp() const { return false; }
            bool isValid() const { return m_type != BuildingType::Unknown; }

            BuildingDetails details() const { return { m_farmId, m_position }; }

            void update(const QVariant &info) override;
            void updateBuildingData(const QVariant &info);

            QString toString() const override;

            BuildingData::Ptr buildingData() const { return m_buildingData; }

        signals:
            void fetchBuildingRequested(BuildingDetails details, BuildingType type) const;
            void buildingChanged() const;

        private:
            void initializeConnections() const;

        private:
            int m_id;
            BuildingType m_type;
            int m_farmId;
            int m_position;
            int m_level;
            int m_animals;
            int m_remaining;

            QDateTime m_doneTimestamp;
            QString m_name;

            BuildingData::Ptr m_buildingData;

        };

    }

}
