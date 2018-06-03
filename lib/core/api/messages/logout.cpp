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

#include "logout.h"
#include "../apigateway.h"

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

using namespace Api;
using namespace Messages;

//void Logout::sendMessage()
//{
//    QNetworkRequest request(buildEndpointUrl("main", {
//        { "page", "logout" },
//        { "logoutbutton", "1" }
//    }, false));

//    buildHeaders(request);

//    auto reply = m_manager->get(request);
//    connect(reply, &QNetworkReply::finished, [this, reply] () {
//        m_gateway->setLoggedIn(false);
//    });
//}

const QUrl Logout::url() const
{
    return m_gateway->buildEndpointUrl("main", {
        { "page", "logout" },
        { "logoutbutton", "1" }
                                       }, false);
}

void Logout::handleResponse(QNetworkReply *reply)
{
    Q_UNUSED (reply)

    m_gateway->setLoggedIn(false);
}
