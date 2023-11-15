#include "MMM.hpp"

MMM::MMM()
{
    one = fireboy();
    two = watergirl();
    SDL_Window *gwindow = NULL;
}

void MMM::draw()
{
    one.draw();
    one.move();
    two.draw();
    two.move();
}
