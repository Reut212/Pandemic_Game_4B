#pragma once
#include "Player.hpp"

namespace pandemic{
    class Medic : public Player{
        
        public:
        Medic(Board &board, City c) : Player(board,c){};
        
        Medic& treat(City cityImIn) override; //special ability for Medic player
        string role() override; //return role name of Medic
        void auto_heal_cities() override; //if cure was found in a city that Medic arrived, he's automatically updated all cure cubes to o

    };
}