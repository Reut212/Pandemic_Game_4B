#include "Player.hpp"
#include <iostream>
using namespace std;

namespace pandemic{

    Player& Player::drive (City neighbourCity){
        if(city == neighbourCity){
            throw invalid_argument("Can't drive from one city to itself!");
        }
        if(!Board::neiCity(city, neighbourCity)){
            throw invalid_argument("those cities are not connected!");
        }
        city = neighbourCity;
        auto_heal_cities();
        return *this;
    }

    Player& Player::fly_direct (City cityOnCard){
        if(city == cityOnCard){
            throw invalid_argument("You can't fly direct to this city");
        }
        if(cards.count(cityOnCard) == 0){
            throw invalid_argument("You don't have the right card");
        }
        city = cityOnCard;
        cards.erase(cityOnCard);
        auto_heal_cities();
        return *this;
    }

    Player& Player::fly_charter (City anyCity){
        if(city == anyCity) {
            throw invalid_argument("You can't fly direct to this city");
        }
        if(cards.find(city) == cards.end()){
            throw invalid_argument("card not fount");
        }
        cards.erase(cards.find(city));
        city = anyCity;
        auto_heal_cities();
        return *this;
    }

    Player& Player::fly_shuttle (City reaserchStationCity){
        if(reaserchStationCity == city){
            throw invalid_argument("you can't fly shuttle from one city to itself!");
        }
            //if those cities are a reaserch station cities
            if(board.isRSCity(reaserchStationCity) && board.isRSCity(city)){
                city = reaserchStationCity;
                auto_heal_cities();
                return *this;
            }
            throw invalid_argument("you can't fly shuttle to this city");
    }

    Player& Player::build (){
        const bool is_in_cards = cards.find(city) != cards.end();
        const bool is_in_RS = board.isRSCity(city);
        if(!is_in_cards && !is_in_RS) {
            throw invalid_argument("No card for build");
        }
        if(board.isRSCity(city)){
            return *this;
        }
        board.insert_RS(city);
        cards.erase(city);
        auto_heal_cities();
        return *this;
    }

    Player& Player::discover_cure (Color colorOfDisease){
        const int limit = 5;
        int counter = 0;
        set<City> fiveCitiesForNow;
        const bool is_in_RS = board.isRSCity(city);
        if(!is_in_RS){
            throw invalid_argument("There is no research station in this city");
        }
        for(City a : cards){
            if(colorOfCity.at(a) == colorOfDisease){
                counter++;
                fiveCitiesForNow.insert(a);
            }
        }
        if(counter < limit){
            fiveCitiesForNow.clear();
            throw invalid_argument("Please check that you have five cards");
        }
        // cout << counter <<endl;
        // cout << fiveCitiesForNow.size() <<endl;
        for(City a : fiveCitiesForNow){
            if(counter == limit){
                cards.erase(a);
                fiveCitiesForNow.erase(a);
                break;}
                Color col = colorOfCity.at(a);
            if(col == colorOfDisease){
                cards.erase(a);
                fiveCitiesForNow.erase(a);
            }
        }
        board.insertCure(colorOfDisease);
        // cout << board.cureColorIsFound(colorOfDisease) <<endl;
        auto_heal_cities();
        return *this;
    }

    Player& Player::take_card(City newCity){
        cards.insert(newCity);
        return *this;
    }

    Player& Player::treat (City cityImIn){
        if(city != cityImIn){
            throw invalid_argument("You are not placed on the right city");
        }
        if(board[city] == 0){
            throw invalid_argument("There is no disease in this city");
        }
        Color c = colorOfCity.at(cityImIn);
        if(board.cureColorIsFound(c)){
            board[city] = 0;
        }
        if(board[city] > 0){
            board[city]--;
        }
        auto_heal_cities();
        return *this;
    }

    void Player::remove_cards(){
        cards.clear();
    }

    string Player::role(){
            return _role;
    };
}
