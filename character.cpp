#include "character.hpp"
#include "drawing.hpp"

character::character(SDL_Rect src, SDL_Rect mover) {
    srcRect = src;
    moverRect = mover;
}

// void character::draw() {
//     SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
// }
