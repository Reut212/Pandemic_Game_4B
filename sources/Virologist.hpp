#pragma once
#include "Player.hpp"

namespace pandemic{

    class Virologist : public Player{

        public:
        Virologist(Board &board, City c):Player(board,c){};
        
        Virologist& treat(City cityImIn) override; //special ability for Virologist player
        string role() override; //return role name of Virologist
    };

}