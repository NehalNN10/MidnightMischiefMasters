#include <iostream>
#include <bits/stdc++.h>
#include "midMischief.hpp"

midMischief::midMischief()
{
    std::cout << "midMischief Ctor Called\n";

    currentLevel = 0; // modify this after every level is completed

    // TODO: create getters in level class

    // ? creating levels here:

    // decide paper positions here: (these are garbage values, will change on the basis of "CAREFUL" planning)

    int *ppX = new int[2];
    int *ppY = new int[2];
    int *gaps = new int[8];
    gaps[0] = 0;
    gaps[1] = 3;
    gaps[2] = 23;
    gaps[3] = 39;
    gaps[4] = 19;
    gaps[5] = 10;
    gaps[6] = 10;
    gaps[7] = 10;
    // gaps = {0, 3, 23, 39, 19, 10, 10, 10};
     map *theMap = new map(gaps);
    ppX[0] = 0;
    ppX[1] = 200;
    ppY[0] = 300;
    ppY[1] = 0;

    // TODO: no cleanup needed, they are handled in the destructor for level

    levels.push_back(new Level(850, 400, 50, 400, 400, 200, ppX, ppY, theMap));

    // TODO: modify map constructor such that it takes in values to create a custom map

    score = 0;
    one = new fireBoy(levels[currentLevel]->getPlayer1X(), levels[currentLevel]->getPlayer1Y());
    two = new waterGirl(levels[currentLevel]->getPlayer2X(), levels[currentLevel]->getPlayer2Y());

    // TODO: modify population of collectiblesList to match the level
    for (int i = 0; i < 2; i++)
    {
        collectiblesList.push_back(new paperOne({levels[currentLevel]->getPapersX()[i], levels[currentLevel]->getPapersY()[i], 50, 50}));
    }

}
midMischief::~midMischief()
{
    std::cout << "midMischief Dtor Called\n";

    for (auto &level : levels)
    {
        delete level;
    }
    delete gwindow;
    gwindow = nullptr;
    delete one;
    delete two;
    one = two = nullptr;
}

bool midMischief::getPaused()
{
    return paused;
}

void midMischief::togglePaused(bool p)
{
    paused = p;
}

void midMischief::drawCharacters()
{
    one->draw();
    two->draw();
    for (auto &element : collectiblesList)
    {
        element->draw();
    }
    // one->printCurrentPosition();
    // two->printCurrentPosition();
}

// asynchronous movement achieved
void midMischief::moveCharacters(const Uint8 *keyStates)
{
    // Movement keys for character 1
    if (keyStates[SDL_SCANCODE_W])
    {
        directionOne = 'U';
    }
    else if (keyStates[SDL_SCANCODE_S])
    {
        directionOne = 'D';
    }
    if (keyStates[SDL_SCANCODE_A])
    {
        directionOne = 'L';
    }
    else if (keyStates[SDL_SCANCODE_D])
    {
        directionOne = 'R';
    }

    // Movement keys for character 2
    if (keyStates[SDL_SCANCODE_UP])
    {
        directionTwo = 'U';
    }
    else if (keyStates[SDL_SCANCODE_DOWN])
    {
        directionTwo = 'D';
    }
    if (keyStates[SDL_SCANCODE_LEFT])
    {
        directionTwo = 'L';
    }
    else if (keyStates[SDL_SCANCODE_RIGHT])
    {
        directionTwo = 'R';
    }

    // passing in characters as they take less space than sdlkey objects
    two->move(directionOne, levels[currentLevel]->getMap());
    one->move(directionTwo, levels[currentLevel]->getMap());
    directionOne = ' ';
    directionTwo = ' ';
}

void midMischief::applyGravity()
{
    one->moverRect.y += 5;
    if (one->moverRect.y >= one->currentY)
    {
        one->moverRect.y = one->currentY;
    }

    two->moverRect.y += 5;
    if (two->moverRect.y >= two->currentY)
    {
        two->moverRect.y = two->currentY;
    }
}

void midMischief::animateCharacters()
{
    one->animation();
    two->animation();

    for (auto &element : collectiblesList)
    {
        element->animation();
    }
}

void midMischief::allCollisions()
{
    for (auto &element : collectiblesList)
    {
        if (collisionClass::collisionChecker(element->moverRect, two->moverRect) && element->collected == false)
        {
            score++;
            element->collected = true;
        }
        if (collisionClass::collisionChecker(element->moverRect, one->moverRect) && element->collected == false)
        {
            score++;
            element->collected = true;
        }
        // deleting collectible after it has been collected
        if (element->collected)
        {
            auto it = std::find(collectiblesList.begin(), collectiblesList.end(), element);
            collectiblesList.erase(it);

            // elementsToDelete.push_back(element);

            // deleting from memory after the element has been collected
            // delete *it;
            // *it = nullptr;
            // delete element;
            // element=nullptr;
        }
    }
    // for (auto d: elementsToDelete)
    // {
    //     delete d;
    // }
}

void midMischief::showScore()
{
    TTF_Init();                                                                              // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24);                                   // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};                                                             // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = std::to_string(score);                                                 // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);            // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {944, 12, 50, 30};                                               // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

void midMischief::textScore()
{
    TTF_Init();                                                                              // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24);                                   // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};                                                             // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = "Pappars collected : ";                                                // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);            // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {774, 12, 130, 30};                                              // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}
