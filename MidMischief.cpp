#include <iostream>
#include <bits/stdc++.h>
#include "midMischief.hpp"

midMischief::midMischief() 
{
    std::cout<<"midMischief Ctor Called\n";
    score = 0;
    one = new fireBoy();
    two = new waterGirl();
    three = new enemy();
    for (int i = 0; i < 5; i++)
    {
        collectiblesList.push_back(new paperOne({rand() % (1000-50), rand() % (400-50), 50, 50}));
    }
}
midMischief::~midMischief() 
{
    std::cout<<"midMischief Dtor Called\n";
    // delete everything here
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
    three->draw();
    // std::cout<<three->moverRect.x<<" "<<three->moverRect.y<<std::endl;
    for (auto &element : collectiblesList)
    {
        element->draw();
    }
    // one->printCurrentPosition();
    // two->printCurrentPosition();
}
void midMischief::chaser()
{
    graph.dijkstra(0,0,one->moverRect.x/map::NUM_BLOCKS_X,one->moverRect.y/map::NUM_BLOCKS_Y);
    std::vector<mapNode> myvec = graph.printPath(one->moverRect.x/map::NUM_BLOCKS_X,one->moverRect.y/map::NUM_BLOCKS_Y);
    for (int i =0; i < myvec.size(); i++) {
        // std::cout<<myvec[i]<<" ";
        // std::cout<<myvec[i].getX()<<" "<<myvec[i].getY();
        // three->draw();
        three->movee(myvec[i].getX()*map::NUM_BLOCKS_X,myvec[i].getY()*map::NUM_BLOCKS_Y);
        // three->moverRect = {myvec[i].getX()*map::NUM_BLOCKS_X,myvec[i].getY()*map::NUM_BLOCKS_Y,50,50};
        // std::cout<<three->moverRect.x<<three->moverRect.y<<std::endl;
        // three->moverRect.y = myvec[i].getY();

    }
    std::cout<<std::endl;
}

// asynchronous movement achieved
void midMischief::moveCharacters(const Uint8* keyStates) 
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
    two->move(directionOne); 
    one->move(directionTwo);
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
    three->animation();

    for (auto &element : collectiblesList)
    {
        element->animation();
    }
}

void midMischief::allCollisions()
{   
    for (auto &element : collectiblesList)
    {
        if (collisionClass::collisionChecker(element->moverRect,two->moverRect) && element->collected == false){
            score++;
            element->collected = true;
        }
        if (collisionClass::collisionChecker(element->moverRect,one->moverRect) && element->collected == false){
            score++;
            element->collected = true;
        }
        // deleting collectible after it has been collected
        if (element->collected)
        {
            auto it = std::find(collectiblesList.begin(), collectiblesList.end(), element);
            collectiblesList.erase(it);
            // deleting from memory after the element has been collected
            // delete *it;
            // *it = nullptr;
        }
    }
}

void midMischief::showScore()
{
    TTF_Init(); // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24); // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0}; // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = std::to_string(score); // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color); // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {944, 12, 50, 30};// create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

void midMischief::textScore()
{
    TTF_Init(); // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24); // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0}; // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = "Pappars collected : "; // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color); // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {774, 12, 130, 30}; // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}
