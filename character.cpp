#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

// // parametized constructor
// character::character(SDL_Rect src, SDL_Rect mover) {
//     srcRect = src;
//     moverRect = mover;
// }

void character::draw() {
    std::cout << "actually drawing anything?" << std::endl;

    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    moverRect.x += 1;
    moverRect.y += 1;

}
