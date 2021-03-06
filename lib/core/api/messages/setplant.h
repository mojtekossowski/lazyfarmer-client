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

#include "onewaymessage.h"
#include "../../data/common.h"

namespace Core {

    namespace Api {

        namespace Messages {

            class SetPlant : public OneWayMessage
            {
                Q_OBJECT

            public:
                using Ptr = QSharedPointer<SetPlant>;

                explicit SetPlant(ApiGateway *gateway,
                                  const Data::BuildingDetails &buindingData = Data::BuildingDetails(),
                                  const Data::ProductDetails &productData = Data::ProductDetails());

                void setBuilding(const Data::BuildingDetails &buindingData) { m_buildingData = buindingData; }
                void setProduct(const Data::ProductDetails &productData) { m_productData = productData; }

            private:
                const QList<QPair<QString, QString> > constructedMessageData() const override;

            private:
                Data::BuildingDetails m_buildingData;
                Data::ProductDetails m_productData;
            };

        }

    }

}
