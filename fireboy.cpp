#include "fireboy.hpp"
#include <iostream>

fireboy::fireboy()
{
    frame = 0;
    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    srcRect = frames[0];
    // default co-ords to spawn character
    moverRect = {850, 400, 50, 50};
}