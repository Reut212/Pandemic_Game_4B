#pragma once
#include "Player.hpp"

namespace pandemic{

  class OperationsExpert : public Player{

    public:
    OperationsExpert(Board &board, City c): Player(board, c){};
    
    OperationsExpert& build() override; //special ability for OperationsExpert player
    string role() override; //return role name of OperationsExpert

  };
}