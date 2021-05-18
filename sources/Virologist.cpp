#include "Virologist.hpp"

namespace pandemic{
    Virologist& Virologist::treat(City cityImIn){

        if(cards.find(cityImIn) == cards.end() && city!=cityImIn){

            throw invalid_argument("No card found");

        }

        Color c = colorOfCity.at(cityImIn);
        if(board.cureColorIsFound(c)){

            board[cityImIn] = 0;

        }

        if(board[cityImIn] > 0){

            cards.erase(cityImIn);
            board[cityImIn]--;
            
        }
        return *this;
    }
    
    string Virologist::role(){
        return "Virologist";
    }
}