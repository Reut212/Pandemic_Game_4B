#include "FieldDoctor.hpp"

namespace pandemic{
    FieldDoctor& FieldDoctor::treat(City cityImIn){
        
        if(!Board::neiCity(city, cityImIn) && city != cityImIn){
            throw invalid_argument("Not a nei City");
        }

        if(board[cityImIn] == 0){
            throw invalid_argument("There is no disease in this city");
        }

        Color c = colorOfCity.at(city);
        if(board.cureColorIsFound(c)){
            board[cityImIn] = 0;
        }

        if(board.numOfCubesInCity(cityImIn) > 0){
            board[cityImIn]--;
        }

        return *this;
    }

    string FieldDoctor::role(){
        return "FieldDoctor";
    }
        
}