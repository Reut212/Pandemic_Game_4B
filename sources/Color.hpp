#pragma once
#include <string>
#include <map>

using namespace std;

namespace pandemic{
    //enum of all colors
    enum Color{
        Yellow,
        Red,
        Blue,
        Black
    };
    //map that include enum as a key and string of enum as a value
    static map<Color, string> stringOfColor{
        {Yellow, "Yellow"},
        {Red, "Red"},
        {Blue, "Blue"}, 
        {Black, "Black"}
    };
    //map that include enum of city as a key and string of enum of color as a value
    inline static map<City, Color> colorOfCity{
        {Algiers, Black},
        {Atlanta, Blue},
        {Baghdad, Black},
        {Bangkok, Red},
        {Beijing, Red},
        {Bogota, Yellow},
        {BuenosAires, Yellow},
        {Cairo, Black},
        {Chennai, Black},
        {Chicago, Blue},
        {Delhi, Black},
        {Essen, Blue},
        {HoChiMinhCity, Red},
        {HongKong, Red},
        {Istanbul, Black},
        {Jakarta, Red},
        {Johannesburg,Yellow},
        {Karachi, Black},
        {Khartoum, Yellow},
        {Kinshasa, Yellow},
        {Kolkata, Black},
        {Lagos, Yellow},
        {Lima, Yellow},
        {London, Blue},
        {LosAngeles, Yellow},
        {Madrid, Blue},
        {Manila, Red},
        {MexicoCity, Yellow},
        {Miami, Yellow},
        {Milan, Blue},
        {Montreal, Blue},
        {Moscow, Black},
        {Mumbai, Black},
        {NewYork,Blue},
        {Osaka, Red},
        {Paris, Blue},
        {Riyadh, Black},
        {SanFrancisco, Blue},
        {Santiago, Yellow},
        {SaoPaulo, Yellow},
        {Seoul, Red},
        {Shanghai, Red},
        {StPetersburg, Blue},
        {Sydney, Red},
        {Taipei, Red},
        {Tehran, Black},
        {Tokyo, Red},
        {Washington, Blue}
    };
}