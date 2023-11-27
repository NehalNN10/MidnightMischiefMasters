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
    first->draw();
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
    first->animation();
}
// for now checks if characters are colliding, need to convert and add collectables
bool MidMischief::checkCollision()
{
    //The sides of the rectangles
    int leftA, leftB, leftP1;
    int rightA, rightB, rightP1;
    int topA, topB, topP1;
    int bottomA, bottomB, bottomP1;

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

    //Calculate the sides for collecteble item

    leftP1 = first->moverRect.x;
    rightP1 = first->moverRect.x + first->moverRect.w;
    topP1 = first->moverRect.y;
    bottomP1 = first->moverRect.y + first->moverRect.h;

    if( bottomA <= topP1 && bottomB <= topP1 )
    {
        return false;
    }

    if( topA >= bottomP1 && topB >= bottomP1 )
    {
        return false;
    }

    if( rightA <= leftP1 && rightB <= leftP1 )
    {
        return false;
    }

    if( leftA >= rightP1 && leftB >= rightP1 )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
