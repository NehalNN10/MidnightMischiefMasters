#include "fireboy.hpp"

fireboy::fireboy() : character({779, 0, 294, 848},{0,0,50,50}){} //default co-ords to spawn character

void fireboy::move() {
    moverRect.x += 3;
    moverRect.y += 2;
}