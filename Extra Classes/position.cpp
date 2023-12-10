#include "position.hpp"

position::position()
{
    x_coord = 0;
    y_coord = 0;
}

int* position::get_coord()
{
    int *coord = new int[2];
    
    coord[0] = x_coord;
    coord[1] = y_coord;

    return coord;
}

void position::set_coord(int x, int y)
{
    x_coord = x;
    y_coord = y;
}