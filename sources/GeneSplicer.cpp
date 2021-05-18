#include "GeneSplicer.hpp"

namespace pandemic{
    GeneSplicer& GeneSplicer::discover_cure(Color colorOfDisease){ //can discover cure with any five cards. No matter if the color is different
        const int limit = 5;
        int counter = 0;
        set<City> fiveCitiesForNow;
        const bool is_in_RS = board.isRSCity(city);
        if(!is_in_RS){
            throw invalid_argument("There is no research station in this city");
        }
        for(City a : cards){
                counter++;
                fiveCitiesForNow.insert(a);
        }
        if(counter < limit){
            fiveCitiesForNow.clear();
            throw invalid_argument("You need to have 5 cards. You only have: " +to_string(counter)+ " cards.");
        }
        // cout << counter <<endl;
        // cout << fiveCitiesForNow.size() <<endl;
        for(City a : fiveCitiesForNow){ //go over all cards and count them
            if(counter == limit){ //if number of city cards equals to 5
                cards.erase(a);
                fiveCitiesForNow.erase(a);
                break;
            }
        }
        board.insertCure(colorOfDisease);
        return *this;
        }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }

    }