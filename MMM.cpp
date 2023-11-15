#include "MMM.hpp"

MMM::MMM()
{
    // one = fireboy();
    // two = watergirl();
    // SDL_Window *gwindow = NULL;
}

void MMM::draw(SDL_Renderer* gRenderer, SDL_Texture* assets)
{
    // one.srsRect;
    // SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    SDL_RenderCopy(gRenderer, assets, &one.srcRect, &one.moverRect);

    // one.draw();
    one.move();
    SDL_RenderCopy(gRenderer, assets, &two.srcRect, &two.moverRect);

    // two.draw();
    two.move();
}
