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

#include "api/apigateway.h"
#include "data/storage.h"
#include "data/farm.h"

#include <QtCore/QObject>

namespace Core {

    class GlobalGameData;

    class Player : public QObject
    {
        Q_OBJECT

    public:
        explicit Player(QObject *parent = nullptr);

        Q_INVOKABLE inline int level() const { return m_level; }
        Q_INVOKABLE inline QString levelDescription() const { return m_levelDescription; }
        Q_INVOKABLE inline int levelPercentage() const { return m_levelPercentage; }
        Q_INVOKABLE inline qreal money() const { return m_money; }

        QSharedPointer<GlobalGameData> gameData() const;

        Api::ApiGateway &gateway() { return m_gateway; }
        Data::Storage::Ptr storage() { return m_storage; }

    public slots:
        void update(const QByteArray &info);

    private:
        void updateBasicInfo(const QVariantMap &basicInfo);
        void initialize();
        void initializeConnections() const;

    private:
        int m_level;
        int m_levelPercentage;

        qreal m_money;
        QString m_levelDescription;

        Data::Storage::Ptr m_storage;
        Data::BuildingList::Ptr m_buildingList;

        Api::ApiGateway m_gateway;
    };

}
