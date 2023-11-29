#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"

MidMischief::MidMischief() {
    score = 0;
    one = new fireboy();
    two = new watergirl();
    // first = new paper1();
    collectibles_list.push_back(new paper1({200,400,50,50}));
}

bool MidMischief::getpaused() { return paused; };
void MidMischief::toggle_paused(bool p) { paused = p; }

void MidMischief::drawchars()
{
    one->draw();
    two->draw();
    for (auto & element : collectibles_list)
    {
        element->draw();
    }
    // first->draw();
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
    // first->animation();
    for (auto & element : collectibles_list)
    {
        element->animation();
    }
}

void MidMischief::allCollisions()
{   
    for (auto & element : collectibles_list)
    {
    if (collisionChecker::collisionCheck(element->moverRect,two->moverRect) && element->collected == false){
    score ++;
    element->collected = true;
    }
    if (collisionChecker::collisionCheck(element->moverRect,one->moverRect) && element->collected == false){
        score ++;
        element->collected = true;
    }
    std::cout<<"Score" << score << std::endl;
    }
}