#include "Medic.hpp"

namespace pandemic{
    Medic& Medic::treat(City cityImIn){
        if(city != cityImIn){
            throw invalid_argument("You are not placed on the right city");
        }
        if(board[city] == 0){
            throw invalid_argument("There is no disease in this city");
        }
        Color c = colorOfCity.at(cityImIn);
        if(board.cureColorIsFound(c)){
            board[city] = 0;
        }
        if(board[city] > 0){
            board[city] = 0;
        }
        return *this;
    }
    
    void Medic::auto_heal_cities(){
        Color c = colorOfCity.at(city);
        if(board.cureColorIsFound(c)){
            board[city] = 0;
        }
    }

    string Medic::role(){
        return "Medic";
    }

}