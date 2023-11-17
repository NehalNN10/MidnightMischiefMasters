#include "MMM.hpp"

MMM::MMM()
{
    // one = fireboy();
    // two = watergirl();
    // SDL_Window *gwindow = NULL;
}

void MMM::draw(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    // draw fireboy and move it
    SDL_RenderCopy(gRenderer, assets, &one.srcRect, &one.moverRect);
    one.move();
    // draw watergirl and move it
    SDL_RenderCopy(gRenderer, assets, &two.srcRect, &two.moverRect);
    two.move();
}
