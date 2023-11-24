#include "watergirl.hpp"
#include <iostream>


watergirl::watergirl() 
{    
    frame = 0;
    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    srcRect = frames[0];
    // default co-ords to spawn character
    moverRect = {50, 400, 50, 50};
}

// // movement of second character done using WASD
// void watergirl::move(char direction) {
//     if (direction == 'U')
//     {
//         if (moverRect.y - y_jump > 0)
//             moverRect.y -= y_jump;
//     }
//     else if (direction == 'D')
//     {
//         if (moverRect.y + y_jump < 550)
//             moverRect.y += y_jump;
//     }
//     else if (direction == 'R')
//     {
//         if (moverRect.x + x_jump < 950)
//             moverRect.x += x_jump;
//     }
//     else if (direction == 'L')
//     {
//         if (moverRect.x - x_jump > 0)
//             moverRect.x -= x_jump;
//     }
// }

