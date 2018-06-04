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

#pragma once

#include "../onewaymessage.h"
#include "../helpers/querystructs.h"

namespace Api {

    namespace Messages {

        class GetProduction : public OneWayMessage
        {
        public:
            explicit GetProduction(ApiGateway *gateway,
                                   const BuildingData &buindingData = BuildingData(),
                                   const ProductionData &productionData = ProductionData());

            void setBuildingData(const BuildingData &buindingData) { m_buildingData = buindingData; }
            void setProductionData(const ProductionData &productionData) { m_productionData = productionData; }

        private:
            const QList<QPair<QString, QString> > constructedMessageData() const override;

        private:
            BuildingData m_buildingData;
            ProductionData m_productionData;
        };

    }

}