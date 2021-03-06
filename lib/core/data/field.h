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

#include "common.h"
#include "iplayerdata.h"

#include <QtCore/QVariantMap>
#include <QtCore/QObject>

#pragma once

namespace Core {

    class Player;

    namespace Data {

        class Field : public IPlayerData
        {
            Q_OBJECT

        public:
            using Ptr = QSharedPointer<Field>;

            explicit Field (int fieldNo, Player *parent = nullptr);
            ~Field() override = default;

            int fieldNo() const { return m_fieldNo; }

            int id() const { return m_id; }
            int remaining() const { return m_remaining; }
            bool isWatered() const { return m_isWatered; }

            QString name() const { return gameData()->productInfo(m_id).name; }
            int size() const { return gameData()->productInfo(m_id).size; }

            bool isEmpty() const { return m_id == 0; }
            bool isMainBlock() const { return m_id != -1; }

            ProductDetails details() const;

            void update(const QVariant &info) override;

        signals:
            void fieldChanged() const;

        private:
            int m_fieldNo;
            int m_id;
            int m_remaining;
            bool m_isWatered;
        };

    }

}
