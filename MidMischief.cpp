#include <iostream>
#include <bits/stdc++.h>
#include "midMischief.hpp"

midMischief::midMischief()
{
    std::cout << "midMischief Ctor Called\n";

    currentLevel = 0; // modify this after every level is completed
    won = false;

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

    int *ppX_2 = new int[2];
    int *ppY_2 = new int[2];
    int *gaps_2 = new int[8];
    gaps_2[0] = 0;
    gaps_2[1] = 3;
    gaps_2[2] = 23;
    gaps_2[3] = 39;
    gaps_2[4] = 19;
    gaps_2[5] = 10;
    gaps_2[6] = 10;
    gaps_2[7] = 10;
    // gaps_2 = {0, 3, 23, 39, 19, 10, 10, 10};
    map *theMap_2 = new map(gaps_2);
    ppX_2[0] = 0;
    ppX_2[1] = 200;
    ppY_2[0] = 300;
    ppY_2[1] = 0;

    int *ppX_3 = new int[2];
    int *ppY_3 = new int[2];
    int *gaps_3 = new int[8];
    gaps_3[0] = 0;
    gaps_3[1] = 3;
    gaps_3[2] = 23;
    gaps_3[3] = 39;
    gaps_3[4] = 19;
    gaps_3[5] = 10;
    gaps_3[6] = 10;
    gaps_3[7] = 10;
    // gaps_3 = {0, 3, 23, 39, 19, 10, 10, 10};
    map *theMap_3 = new map(gaps_3);
    ppX_3[0] = 0;
    ppX_3[1] = 200;
    ppY_3[0] = 300;
    ppY_3[1] = 0;

    // TODO: no cleanup needed, they are handled in the destructor for level

    levels.push_back(new Level(850, 400, 50, 400, 400, 200, ppX, ppY, theMap));
    levels.push_back(new Level(850, 400, 50, 400, 400, 200, ppX_2, ppY_2, theMap_2));
    levels.push_back(new Level(850, 400, 50, 400, 400, 200, ppX_3, ppY_3, theMap_3));

    loadLevel(false);

    delete[] gaps;
}

void midMischief::loadLevel(bool x) // x indicates if level is currently on screen
{
    if (x)
    {
        delete one;
        delete two;
        for (auto &element : collectiblesList)
        {
            delete element;
        }
        collectiblesList.clear();
    }

    score = 0;
    one = new fireBoy(levels[currentLevel]->getPlayer1X(), levels[currentLevel]->getPlayer1Y());
    two = new waterGirl(levels[currentLevel]->getPlayer2X(), levels[currentLevel]->getPlayer2Y());

    for (int i = 0; i < 2; i++)
    {
        collectiblesList.push_back(new paperOne({levels[currentLevel]->getPapersX()[i], levels[currentLevel]->getPapersY()[i], 50, 50}));
    }

    //TODO: add level completion code i.e. change level once both papers collected
}

void midMischief::handleLevels()
{
    if (collectiblesList.empty())
    {
        if (currentLevel < 2)
        {
            std::cout << "Level " << currentLevel+1 << " passed!" << std::endl;
            currentLevel++;
            loadLevel(true);
        }
        else
        {
            std::cout << "You have won the game!" << std::endl;
            setWon(true);
        }
    }
}


midMischief::~midMischief()
{
    // deleting all the levels and characters and everything in heap.
    std::cout << "midMischief Dtor Called\n";

    for (auto &level : levels)
    {
        delete level; // would call ~level() which would delete everything there as well
    }

    std::cout << levels.capacity() << std::endl;

    delete gwindow;
    gwindow = nullptr;
    delete one;
    delete two;
    one = two = nullptr;
    for (auto &collectible : collectiblesList)
    {
        delete collectible;
    }
}

// for pausing and unpausing the game

bool midMischief::getPaused()
{
    return paused;
}

void midMischief::togglePaused(bool p)
{
    paused = p;
}

// draw both characters as well as the collectibles
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

// applying gravity to both characters, wont be used after graph implmentation
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

// animating all the characters and all the collectibles
void midMischief::animateCharacters()
{
    one->animation();
    two->animation();

    for (auto &element : collectiblesList)
    {
        element->animation();
    }
}

// checking collision between both characters and all the collectibles, if any found then score++
void midMischief::allCollisions()
{
    for (auto &element : collectiblesList)
    {   
        if (*one == element && element->collected == false) // operator overloading to check for collisions
        {
            score++; // score increments
            element->collected = true; // making sure that element is deleted later after being collected
        }
        // player two
        if (*two == element && element->collected == false) // operator overloading to check for collisions
        {
            score++;
            element->collected = true;
        }
        // deleting collectible after it has been collected
        if (element->collected)
        {
            auto it = std::find(collectiblesList.begin(), collectiblesList.end(), element);
            collectiblesList.erase(it);
        }
    }
}

// Showing the score!
void midMischief::showScore()
{
    TTF_Init();// Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24);// Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};// This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = std::to_string(score);// converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);// A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage);// Converts into texture that can be displayed
    SDL_Rect Message_rect = {944, 12, 50, 30};// create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

// Showing "Score:"
void midMischief::textScore()
{
    TTF_Init();// Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24);// Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 255};// This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = "Papers collected : ";// converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);// A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage);// Converts into texture that can be displayed
    SDL_Rect Message_rect = {774, 12, 130, 30};// create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

// bool midMischief::winCondition() 
// {
//     if (score == 2)
//         return true;
//     return false;
// }