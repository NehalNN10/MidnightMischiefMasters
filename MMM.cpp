#include "MMM.hpp"
#include "drawing.hpp"
#include "iostream"

MMM::MMM()
{
    // one = fireboy();
    // two = watergirl();
    // SDL_Window *gwindow = NULL;
}

void MMM::drawchars()
{
    // srcRect, moverRect
    // draw fireboy and move it
    // SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &one.srcRect, &one.moverRect);
    // // draw watergirl and move it
    // SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &two.srcRect, &two.moverRect);
    std::cout << "drawing both characters?" << std::endl;

    one->draw();
    two->draw();
    std::cout<<one->moverRect.x<<std::endl;
}

void MMM::movechars(SDL_Keycode key, Uint32 eventType) 
{
    // if(eventType == SDL_KEYDOWN){ //if key is pressed only then movement is called.
        // two.move(key);
        // one.move(key);
    // }
}
