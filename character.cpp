#include "character.hpp"

character::character(SDL_Rect srs, SDL_Rect mover) {
    srsRect = srs;
    moverRect = mover;
}

character::draw() {
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
