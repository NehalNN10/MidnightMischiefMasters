#include "watergirl.hpp"

watergirl::watergirl() : character({779, 0, 294, 848},{0,0,50,50}){}

watergirl::move() {
    moverRect.x += 2;
    moverRect.y += 3;
}