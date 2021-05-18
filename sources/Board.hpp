#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <ostream>
#include <map>
#include <set>

using namespace std;

namespace pandemic{

    class Board{
        
            static map<City, set<City>> cities;
            set<City> rSCities;
            map<City, int> cubes;
            set<Color> cures;

        public:
        Board(); //Initialize a new board

        int& operator[](City c); //put disease cubes in a specific city
        bool is_clean() const ; //check if there is disease cubes on the board
        void remove_cures(); //remove all mediciens from the board
        void remove_stations(); //delete all reasearch stations from the board
        void insertCure(Color a); //insert cure according to specific color
        bool isRSCity(City a); //check if this city has a research station
        void insert_RS(City a); //insert a research station according to specific color
        bool cureColorIsFound(Color a); //check if a cure is found
        static bool neiCity(const City& a, const City& b); //return if those coties are neighbours
        int numOfCubesInCity(City a); //check how much deasise cubes in a specific city
        friend ostream& operator<<(ostream& out, Board const& b); //print board
    };
}