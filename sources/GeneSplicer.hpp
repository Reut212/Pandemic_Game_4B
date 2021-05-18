#pragma once
#include "Player.hpp"

namespace pandemic{
    class GeneSplicer : public Player {

        public:
        GeneSplicer(Board &board, City c) : Player(board,c){};
        
        GeneSplicer& discover_cure(Color colorOfDisease) override; //special ability for GeneSplicer player
        string role() override; //return role name of GeneSplicer

    };
}