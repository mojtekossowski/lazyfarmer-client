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

#include "player.h"

#include <QtCore/QAbstractListModel>

namespace Model {

    class PlayerFactoryModel : public QAbstractListModel
    {
        Q_OBJECT

    public:
        enum class PlayerRoles {
            Description     = Qt::DisplayRole,
            Level           = Qt::UserRole,
            LevelDescription,
            LevelPercentage,
            Money,
            CurrentJob,
            PlayerObject,
            LastError
        };

        explicit PlayerFactoryModel(QObject *parent = nullptr);
        ~PlayerFactoryModel() override = default;

        int rowCount(const QModelIndex &parent) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QHash<int, QByteArray> roleNames() const override;

        Core::Player::Ptr create();

        Q_INVOKABLE void createPlayer() { create(); }
        Q_INVOKABLE void removeAt(int row);

        Q_INVOKABLE QVariant at(int row);

    private:
        QList<Core::Player::Ptr> m_players;

    };

}
