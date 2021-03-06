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

#include "storage.h"
#include "player.h"
#include "globalgamedata.h"

#include <QtCore/QVariantList>

#include <QtDebug>

using namespace Core;
using namespace Core::Data;

QString Storage::nameAtRow(int row) const
{
    return gameData()->productInfo(idAtRow(row)).name;
}

void Storage::update(const QVariant &info)
{
    const QVariantList storageData = info.toList();

    m_products.clear();

    for (const auto &item : storageData) {
        const auto product = item.toMap();

        int id = product["Id"].toInt();
        int amount = product["Amount"].toInt();

        m_products.insert(id, amount);
    }

    IPlayerData::update(info);
    emit storageChanged();
}

QString Storage::toString() const
{
    QStringList storageContents;

    QMapIterator<int, int> product (m_products);
    while(product.hasNext()) {
        product.next();

        const auto id = product.key();
        const auto name = gameData()->productInfo(id).name;
        const auto amount = product.value();
        storageContents.append(QString("(%1 (id: %2): %3)")
                               .arg(name).arg(id).arg(amount));
    }

    return QString("Storage: (%1)").arg(storageContents.join(", "));
}
