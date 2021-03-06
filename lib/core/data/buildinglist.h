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

#include "building.h"
#include "iplayerdata.h"

#include <QtCore/QSharedPointer>

namespace Core {

    class Player;

    namespace Data {

        class BuildingList : public IPlayerData
        {
            Q_OBJECT

        public:
            using Ptr = QSharedPointer<BuildingList>;

            explicit BuildingList (Player *parent = nullptr);
            ~BuildingList() override = default;

            Building::Ptr buildingAt(int farm, int position);
            Building::Ptr buildingAt(int index);

            void update(const QVariant &info) override;

            QString toString() const override;

            int size() const { return m_buildings.size(); }

        signals:
            void buildingChanged(int index) const;

        public slots:
            void updateBuilding(int farm, int position, const QVariant &info);

        private:
            QList<Building::Ptr> m_buildings;

        };

    }

}
