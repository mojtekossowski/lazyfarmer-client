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

#include <QtCore/QVariantMap>
#include <QtCore/QObject>

namespace Core {

    namespace Data {

        class Building : public QObject
        {
            Q_OBJECT

        public:
            explicit Building(QObject *parent = nullptr);
            Building (const QVariantMap &buildingInfo, QObject *parent = nullptr);

            void update(const QVariantMap &buildingInfo);

            int type() const { return m_type; }
            int farmId() const { return m_farmId; }
            int position() const { return m_position; }
            int level() const { return m_level; }
            int animals() const { return m_animals; }
            int remaining() const { return m_remaining; }

        signals:
            void buildingChanged();

        private:
            int m_type;
            int m_farmId;
            int m_position;
            int m_level;
            int m_animals;
            int m_remaining;

        };

    }

}
