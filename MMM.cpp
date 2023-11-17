#include "MMM.hpp"

MMM::MMM()
{
    // one = fireboy();
    // two = watergirl();
    // SDL_Window *gwindow = NULL;
}

void MMM::draw(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key, Uint32 eventType)
{
    // draw fireboy and move it
    SDL_RenderCopy(gRenderer, assets, &one.srcRect, &one.moverRect);
    // draw watergirl and move it
    SDL_RenderCopy(gRenderer, assets, &two.srcRect, &two.moverRect);
    if(eventType == SDL_KEYDOWN){ //if key is pressed only then movement is called.
        two.move(key);
        one.move(key);
    }
}
