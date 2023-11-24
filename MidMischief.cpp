#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"

MidMischief::MidMischief() {}

bool MidMischief::getpaused() { return paused; };
void MidMischief::toggle_paused(bool p) { paused = p; }

void MidMischief::drawchars()
{
    one->draw();
    two->draw();
}


//asynchronous movement achieved
void MidMischief::movechars(const Uint8* keystates) 
{
    // Movement keys for character 1
    if (keystates[SDL_SCANCODE_W])
    {
        direction_1 = 'U';
    }
    else if (keystates[SDL_SCANCODE_S])
    {
        direction_1 = 'D';
    }
    else if (keystates[SDL_SCANCODE_A])
    {
        direction_1 = 'L';
    }
    else if (keystates[SDL_SCANCODE_D])
    {
        direction_1 = 'R';
    }

    // Movement keys for character 2
    if (keystates[SDL_SCANCODE_UP])
    {
        direction_2 = 'U';
    }
    else if (keystates[SDL_SCANCODE_DOWN])
    {
        direction_2 = 'D';
    }
    else if (keystates[SDL_SCANCODE_LEFT])
    {
        direction_2 = 'L';
    }
    else if (keystates[SDL_SCANCODE_RIGHT])
    {
        direction_2 = 'R';
    }
    two->move(direction_1); //passing in characters as they take less space than sdlkey objects 
    one->move(direction_2);
    direction_1 = ' ';
    direction_2 = ' ';
}

void MidMischief::animatechars()
{
    one->animation();
    two->animation();
}
// for now checks if characters are colliding, need to convert and add collectables
bool MidMischief::checkCollision()
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = one->moverRect.x;
    rightA = one->moverRect.x + one->moverRect.w;
    topA = one->moverRect.y;
    bottomA = one->moverRect.y + one->moverRect.h;

    //Calculate the sides of rect B
    leftB = two->moverRect.x;
    rightB = two->moverRect.x + two->moverRect.w;
    topB = two->moverRect.y;
    bottomB = two->moverRect.y + two->moverRect.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
