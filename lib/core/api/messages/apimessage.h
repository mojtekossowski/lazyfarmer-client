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

#include "../apigatewayerror.h"
#include "messagetypes.h"

class QNetworkReply;
#include <QtNetwork/QNetworkRequest>

namespace Api {

    class ApiGateway;

    namespace Messages {

        class ApiMessage : public QObject
        {
            Q_OBJECT

        public:
            explicit ApiMessage(ApiGateway *gateway,
                                MessageType messageType = MessageType::Unknown,
                                bool isLoginRequired = true);

            virtual ~ApiMessage();

            bool isSent() const { return m_isSent; }
            void setIsSent(bool isSent) { m_isSent = isSent; }

            virtual QueryType queryType() const { return QueryType::Get; }

            virtual const QUrl url() const = 0;
            virtual void configureRequest(QNetworkRequest &request) const { Q_UNUSED (request) }
            virtual const QList<QPair<QString, QString>> postData() const { return {}; }

            virtual void handleResponse(QNetworkReply *reply) = 0;

        signals:
            void raiseError(ApiGatewayError::ErrorType errorType, const QStringList &args = QStringList());
            void finished();

        protected:
            ApiGateway *m_gateway;

            MessageType m_messageType;

            bool m_isLoginRequired;
            bool m_isSent;
        };
    }

}
