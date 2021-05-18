#include "Researcher.hpp"

namespace pandemic{
    Researcher& Researcher::discover_cure(Color colorOfDisease){
        set<City> fiveCitiesForNow;
        if(board.cureColorIsFound(colorOfDisease)){
            return *this;
        }
        const int limit = 5;
        int counter = 0;
        for(City a : cards){
            Color col = colorOfCity.at(a);
            if(col == colorOfDisease){
                fiveCitiesForNow.insert(a);
                counter++;
            }
        }
        if(counter < limit){
            fiveCitiesForNow.clear();
            throw invalid_argument("You need to have 5 cards. You only have: " +to_string(counter)+ " cards.");
        }

        counter = 0;
        for(auto goOverCards = cards.begin(); goOverCards != cards.end(); counter++){ //go over all cards and count them
            if(counter == limit){ //if number of city cards equals to 5
                fiveCitiesForNow.clear();
                break;}
            if(colorOfCity.at(*goOverCards) == colorOfDisease){ //if color of this city equals to the color of disease
                goOverCards = cards.erase(goOverCards); //throw the city card
            }else{
                goOverCards++; //else go over another city card and malke the same search
            }
        }
        board.insertCure(colorOfDisease); //you found cure
        return *this;
    }

    string Researcher::role(){
        return "Researcher";
    }

}