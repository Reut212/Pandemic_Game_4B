#pragma once
#include "Player.hpp"

namespace pandemic{
    class Dispatcher : public Player{

        public:
        Dispatcher(Board &board, City c) : Player(board, c){};
        
        Dispatcher& fly_direct(City cityOnCard) override; //special ability for Dispatcher player
        string role() override; //return role name of Dispatcher
        
    };
}