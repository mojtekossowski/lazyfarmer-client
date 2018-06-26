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

#include "../globalgamedata.h"

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtCore/QSharedPointer>

namespace Core {

    class Player;

    namespace Data {

        class IPlayerData : public QObject
        {
            Q_OBJECT

        public:
            explicit IPlayerData(Player *parent = nullptr);

            virtual void update(const QVariant &info) = 0;
            virtual QString toString() const;

            GlobalGameData::Ptr gameData() const;

        protected:
            Player *m_owner;

        };

    }

}
