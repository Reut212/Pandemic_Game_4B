#pragma once

#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player{
        int n;
        
        public:
        Scientist(Board &board, City c, int a = 4) : Player(board,c),n(a){};
        
        Scientist& discover_cure(Color colorOfDisease) override; //special ability for Scientist player
        string role() override; //return role name of Scientist

    };
}