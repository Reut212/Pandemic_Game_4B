#pragma once
#include "Board.hpp"

using namespace std;

namespace pandemic{
    class Player{

        protected:
        Board& board;
        City city;
        string _role;
        set<City> cards;

        public:
        Player(Board& b, City c):board(b), city(c){};

        Player& take_card(City newCity); //take a new card
        virtual Player& drive (City neighbourCity); //drive to a neighbour city
        virtual Player& fly_direct (City cityOnCard); //fly to another city. only if you have a card with the name of the city and you throw it
        virtual Player& fly_charter (City anyCity); //fly to another city. You should throw the card of the city you left
        virtual Player& fly_shuttle (City reaserchStationCity); //fly to anothe city with reaserch staion only if your city has a reaserch station as well
        virtual Player& build (); //build a reaserch station in this city
        virtual Player& discover_cure (Color colorOfDisease); //discover a cure to some disease (according to color). You should throw 5 cards with the color of the disease
        virtual Player& treat (City cityImIn); //decrease one cube from this city
        virtual string role(); //return role names of special players
        void remove_cards(); //remove all cards 
        virtual void auto_heal_cities(){}; //a function for Medic's special ability.
    
    };
}