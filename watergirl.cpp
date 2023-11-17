#include "watergirl.hpp"

watergirl::watergirl() : character({779, 0, 294, 848},{0,0,50,50}){} //default spawning location

void watergirl::move() { // move it diagnally, same implementation as fireboy needed here except that it would be with WASD keys
    moverRect.x += 2;
    moverRect.y += 3;
}