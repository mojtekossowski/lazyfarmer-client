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

#include <QtCore/QAbstractItemModel>

namespace Core {

    namespace Model {

        class StorageModel : public QAbstractItemModel
        {
            Q_OBJECT

        public:
            explicit StorageModel(QObject *parent = nullptr);

            // Header:
            QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

            bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

            // Basic functionality:
            QModelIndex index(int row, int column,
                              const QModelIndex &parent = QModelIndex()) const override;
            QModelIndex parent(const QModelIndex &index) const override;

            int rowCount(const QModelIndex &parent = QModelIndex()) const override;
            int columnCount(const QModelIndex &parent = QModelIndex()) const override;

            QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

            // Editable:
            bool setData(const QModelIndex &index, const QVariant &value,
                         int role = Qt::EditRole) override;

            Qt::ItemFlags flags(const QModelIndex& index) const override;

            // Add data:
            bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
            bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

            // Remove data:
            bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
            bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

        private:
        };

    }


}
