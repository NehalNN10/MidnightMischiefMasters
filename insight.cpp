#include "insight.hpp"
#include "mover.hpp"
#include <string>
#include <vector>

void makeMove(std::string direction){
    if (direction == "East"){
        moveEast();
    }
    else if (direction == "West"){
        moveWest();
    }
    else if (direction == "North"){
        moveNorth();
    }
    else if (direction == "South"){
        moveSouth();
    }
}
