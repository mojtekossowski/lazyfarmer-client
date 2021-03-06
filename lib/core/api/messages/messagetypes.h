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

#include <QtCore/QString>
#include <QtCore/QCoreApplication>

namespace Core {

    namespace Api {

        namespace Messages {

            enum class QueryType {
                Post,
                Get,

                Unknown
            };

            enum class MessageType {
                Login, // Done
                CheckCredentials, // Done
                Logout, // Done

                GetConstantData, // Done
                GetResource, // Done

                GetFarmInfo, // Todo
                GetFieldInfo,

                SetPlant, // Done
                SetPour, // Done
                GetCollect, // Done

                SetFeed, // Done
                GetFeed,
                GetFeedInfo,

                SetProduction, // Done
                GetProduction, // Done
                GetProductionInfo, //Done

                SetBuyer,
                GetBuyer,

                GetPricesOnMarket,
                SetOfferOnMarket,

                Unknown
            };

            struct MessageHelper
            {

                static QString toReadableString(MessageType type)
                {
                    switch (type) {
                    case MessageType::Login:                return qApp->translate("MessageTypes", "Login in");
                    case MessageType::CheckCredentials:     return qApp->translate("MessageTypes", "Checking Credentials");
                    case MessageType::Logout:               return qApp->translate("MessageTypes", "Logging out");
                    case MessageType::GetConstantData:      return qApp->translate("MessageTypes", "Getting Constant Data");
                    case MessageType::GetResource:          return qApp->translate("MessageTypes", "Getting Resource (%1)");
                    case MessageType::GetFarmInfo:          return qApp->translate("MessageTypes", "Getting Farm Info");
                    case MessageType::GetFieldInfo:         return qApp->translate("MessageTypes", "Getting Field Info");
                    case MessageType::SetPlant:             return qApp->translate("MessageTypes", "Setting Plant");
                    case MessageType::SetPour:              return qApp->translate("MessageTypes", "Setting Pour");
                    case MessageType::GetCollect:           return qApp->translate("MessageTypes", "Getting Collect");
                    case MessageType::SetFeed:              return qApp->translate("MessageTypes", "Setting Feed");
                    case MessageType::GetFeed:              return qApp->translate("MessageTypes", "Getting Feed");
                    case MessageType::GetFeedInfo:          return qApp->translate("MessageTypes", "Getting Feed Info");
                    case MessageType::SetProduction:        return qApp->translate("MessageTypes", "Setting Production");
                    case MessageType::GetProduction:        return qApp->translate("MessageTypes", "Getting Production");
                    case MessageType::GetProductionInfo:    return qApp->translate("MessageTypes", "Getting Production Info");
                    case MessageType::SetBuyer:             return qApp->translate("MessageTypes", "Setting Buyer");
                    case MessageType::GetBuyer:             return qApp->translate("MessageTypes", "Getting Buyer");
                    case MessageType::GetPricesOnMarket:    return qApp->translate("MessageTypes", "Getting Prices On Market");
                    case MessageType::SetOfferOnMarket:     return qApp->translate("MessageTypes", "Setting Offer On Market");
                    default:                                return qApp->translate("MessageTypes", "Unknown");
                    }
                }

                static QString toString(MessageType type)
                {
                    switch (type) {
                    case MessageType::Login:                return "Login";
                    case MessageType::CheckCredentials:     return "CheckCredentials";
                    case MessageType::Logout:               return "Logout";
                    case MessageType::GetConstantData:      return "GetConstantData";
                    case MessageType::GetResource:          return "GetResource";
                    case MessageType::GetFarmInfo:          return "GetFarmInfo";
                    case MessageType::GetFieldInfo:         return "GetFieldInfo";
                    case MessageType::SetPlant:             return "SetPlant";
                    case MessageType::SetPour:              return "SetPour";
                    case MessageType::GetCollect:           return "GetCollect";
                    case MessageType::SetFeed:              return "SetFeed";
                    case MessageType::GetFeed:              return "GetFeed";
                    case MessageType::GetFeedInfo:          return "GetFeedInfo";
                    case MessageType::SetProduction:        return "SetProduction";
                    case MessageType::GetProduction:        return "GetProduction";
                    case MessageType::GetProductionInfo:    return "GetProductionInfo";
                    case MessageType::SetBuyer:             return "SetBuyer";
                    case MessageType::GetBuyer:             return "GetBuyer";
                    case MessageType::GetPricesOnMarket:    return "GetPricesOnMarket";
                    case MessageType::SetOfferOnMarket:     return "SetOfferOnMarket";
                    default:                                return "Unknown";
                    }
                }

            };

        }

    }

}
