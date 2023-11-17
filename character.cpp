#include "character.hpp"
#include "drawing.hpp"

// parametized constructor
character::character(SDL_Rect src, SDL_Rect mover) {
    srcRect = src;
    moverRect = mover;
}

// not working right now for some reason, some problem with Drawing class
// void character::draw() {
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
// }
