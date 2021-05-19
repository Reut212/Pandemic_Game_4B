#include "Board.hpp"
#include <fstream>
#include <sstream>

using namespace std;
using namespace pandemic;

Board::Board(){
        // readFile();
}   

void Board::readFile(){
        ifstream f ("/cities_map.txt");
        string line;
        string cit;
        string col;
        string neighbour;

        while(getline(f, line)){

                istringstream iss(line);
                set <City> nei;
                iss >> cit;
                iss >> col;

                cubes[stringNum.at(cit)]=0;
                while(iss >> neighbour){
                        cities[stringNum.at(cit)].insert(stringNum.at(neighbour));
                }

        }
}
//put disease cubes in a specific city
int& Board::operator[] (City c){
        return cubes[c]; 
}

bool Board::is_clean() const{ 
        for(const auto& it : cubes){
                if(it.second > 0){
                        return false;
                }
        }
        return true;
}

void Board::remove_cures(){
        cures.clear();
}

void Board::remove_stations(){
        rSCities.clear();
}

ostream& pandemic::operator<<(ostream& out, Board const& b){

        out << "\n\tDisease level in each city: \n";
        for(const auto& it : b.cubes){
                out << "\t\t" << stringOfCities.at(it.first) << " --> " << it.second << endl;
        }
        out << "\n\tColor of Cures that found 'till now: \n";
        for(const auto& it2 : b.cures){
                out << "\t\tColor of cure: " << stringOfColor.at(it2)<< endl;
        }
        out << "\n\tReaserch Stations that build 'till now: \n";
        for(const auto& it3 : b.rSCities){
                out << "\t\tReaserch Station is in: " << stringOfCities.at(it3) << ". " <<endl;
        }
        out << "\n---------------------------------------------------------" << "\n" <<endl;
        return out; 
}

bool Board::neiCity(const City& a, const City& b){
        return (cities.at(a).count(b) > 0);
}

void Board::insert_RS(City a){
        rSCities.insert(a);
}

bool Board::cureColorIsFound(Color a){
        return cures.find(a) != cures.end();
}

int Board::numOfCubesInCity(City a){
        return cubes.at(a);
}

void Board::insertCure(Color a){
       cures.insert(a);
}

bool Board::isRSCity(City a){
        return rSCities.find(a) != rSCities.end();
}

map<City, set<City>> Board::cities{
        {Algiers ,{Madrid, Paris, Istanbul, Cairo}},
        {Atlanta ,{Chicago, Miami, Washington}},
        {Baghdad ,{Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok ,{Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing ,{Shanghai, Seoul}},
        {Bogota ,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires,{Bogota, SaoPaulo}},
        {Cairo ,{Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai ,{Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago ,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi ,{Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen ,{London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity ,{Jakarta, Bangkok, HongKong, Manila}},
        {HongKong ,{Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul ,{Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta ,{Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg ,{Kinshasa, Khartoum}},
        {Karachi ,{Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum ,{Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa ,{Lagos, Khartoum, Johannesburg}},
        {Kolkata ,{Delhi, Chennai, Bangkok, HongKong}},
        {Lagos ,{SaoPaulo, Khartoum, Kinshasa}},
        {Lima ,{MexicoCity, Bogota, Santiago}},
        {London ,{NewYork, Madrid, Essen, Paris}},
        {LosAngeles ,{SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid ,{London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila ,{Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity ,{LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami ,{Atlanta, MexicoCity, Washington, Bogota}},
        {Milan ,{Essen, Paris, Istanbul}},
        {Montreal ,{Chicago, Washington, NewYork}},
        {Moscow ,{StPetersburg, Istanbul, Tehran}},
        {Mumbai ,{Karachi, Delhi, Chennai}},
        {NewYork ,{Montreal, Washington, London, Madrid}},
        {Osaka ,{Taipei, Tokyo}},
        {Paris ,{Algiers, Essen, Madrid, Milan, London}},
        {Riyadh ,{Baghdad, Cairo, Karachi}},
        {SanFrancisco ,{LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago ,{Lima}},
        {SaoPaulo ,{Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul ,{Beijing, Shanghai, Tokyo}},
        {Shanghai ,{Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg ,{Essen, Istanbul, Moscow}},
        {Sydney ,{Jakarta, Manila, LosAngeles}},
        {Taipei ,{Shanghai, HongKong, Osaka, Manila}},
        {Tehran ,{Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo ,{Seoul, Shanghai, Osaka, SanFrancisco}},
        {Washington ,{Atlanta, NewYork, Montreal, Miami}}
};
