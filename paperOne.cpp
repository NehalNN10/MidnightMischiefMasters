#include <iostream>
#include "paperOne.hpp"

paperOne::paperOne(SDL_Rect mR)
{   
    std::cout<<"paperOne Ctor Called\n";
    
    // 15 different animation types
    frames[0] = {123, 82, 284, 232};
    frames[1] = {608, 90, 302, 222};
    frames[2] = {1152, 98, 307, 240};
    frames[3] = {1680, 100, 304, 240};
    frames[4] = {108, 466, 304, 240};
    frames[5] = {1680, 100, 304, 240};
    frames[6] = {1152, 98, 307, 240};
    frames[7] = {608, 90, 302, 222};
    frames[8] = {123, 82, 284, 232};

    // first frame for animation
    frame = 0;
    srcRect = frames[0];
    
    // spawn at specific locations
    moverRect = mR;
}

paperOne::~paperOne()
{
    std::cout<<"paperOne Dtor Called\n";
}
