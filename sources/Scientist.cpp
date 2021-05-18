#include "Scientist.hpp"
#include <iostream>
#include <vector>

namespace pandemic{
    Scientist& Scientist::discover_cure(Color colorOfDisease){
        set<City> fiveCitiesForNow;
        if(board.cureColorIsFound(colorOfDisease)){
            return *this;
        }
        int counter = 0;
        const bool is_in_RS = board.isRSCity(city);
        if(!is_in_RS){
            throw invalid_argument("There is no research station in this city");
        }
        
        for(City a : cards){
            Color col = colorOfCity.at(a);
            if(col == colorOfDisease){
                fiveCitiesForNow.insert(a);
                counter++;
            }
        }
        if(counter < n){
            fiveCitiesForNow.clear();
            throw invalid_argument("You need to have 5 cards. You only have: " +to_string(counter)+ " cards.");
        }
        counter = 0;
         for(auto goOverCards = cards.begin(); goOverCards != cards.end(); counter++){ //go over all cards and count them
            if(counter == n){ //if number of city cards equals to 5
            fiveCitiesForNow.clear();
                break;}
            if(colorOfCity.at(*goOverCards) == colorOfDisease){ //if color of this city equals to the color of disease
                goOverCards = cards.erase(goOverCards); //throw the city card
            }else{
                goOverCards++; //else go over another city card and make the same search
            }
        }
        board.insertCure(colorOfDisease); //you found cure
        return *this;
    }

    string Scientist::role(){
        return "Scientist";
    }

}