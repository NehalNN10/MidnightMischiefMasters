#include "insight.hpp"
#include "mover.hpp"
#include <vector>

void makeMove(string direction){
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
