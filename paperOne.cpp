#include <iostream>
#include "paperOne.hpp"

paperOne::paperOne(SDL_Rect mR)
{   
    std::cout<<"paperOne Ctor Called\n";
    
    // 15 different animation types
    frames[0] = {34, 130, 124, 49};
    frames[1] = {226, 124, 124, 55};
    frames[2] = {418, 116, 124, 63};
    frames[3] = {610, 106, 124, 73};
    frames[4] = {802, 95, 124, 84};
    frames[5] = {34, 277, 124, 94};
    frames[6] = {226, 268, 124, 103};
    frames[7] = {418, 262, 124, 109};
    frames[8] = {610, 260, 124, 111};
    frames[9] = {802, 261, 124, 110};
    frames[10] = {34, 453, 124, 110};
    frames[11] = {226, 454, 124, 109};
    frames[12] = {418, 455, 124, 108};
    frames[13] = {610, 457, 124, 106};
    frames[14] = {803, 458, 123, 104};

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
