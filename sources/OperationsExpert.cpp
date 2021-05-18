#include "OperationsExpert.hpp"

namespace pandemic{
    OperationsExpert& OperationsExpert::build(){
        board.insert_RS(city);
        return *this;
    }

    string OperationsExpert::role(){
        return "OperationsExpert";
    }

}