#pragma once
#include "Player.hpp"

namespace pandemic{
    
    class FieldDoctor : public Player{

        public:
        FieldDoctor(Board &board, City c):Player(board, c){};
        
        FieldDoctor& treat(City cityImIn) override; //special ability for FieldDoctor player
        string role() override; //return role name of FieldDoctor

    };
}