#pragma once
#include "Player.hpp"

namespace pandemic{
    class Researcher : public Player{
        
        public:
        Researcher(Board &board, City c) : Player(board,c){};
        
        Researcher& discover_cure(Color colorOfDisease) override; //special ability for Researcher player
        string role() override; //return role name of Researcher

    };
}