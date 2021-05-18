#include "Dispatcher.hpp"

namespace pandemic{
    Dispatcher& Dispatcher::fly_direct(City cityOnCard){
        const bool is_in_RSCity = board.isRSCity(city);
        if(cityOnCard != city && is_in_RSCity){
            city = cityOnCard;
            return *this;
        }
        if(city == cityOnCard){
            throw invalid_argument("You can't fly direct to this city");
        }
        if(cards.count(cityOnCard) == 0){
            throw invalid_argument("You don't have the right card");
        }
        city = cityOnCard;
        cards.erase(cityOnCard);
        return *this;
    }
    string Dispatcher::role(){
        return "Dispatcher";
    }
}