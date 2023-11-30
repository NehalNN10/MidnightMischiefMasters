#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"
#include <bits/stdc++.h>

MidMischief::MidMischief() {
    score = 0;
    one = new fireboy();
    two = new watergirl();
    // first = new paper1();
    // collectibles_list.push_back(new paper1({200,400,50,50}));
    //? drawing random collectibles for testing purposes
    for (int i = 0; i < 5; i++)
    {
        collectibles_list.push_back(new paper1({rand() % 1000-50, rand() % 400-50, 50, 50}));
    }
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
        score++;
        element->collected = true;
    }
    if (collisionChecker::collisionCheck(element->moverRect,one->moverRect) && element->collected == false){
        score++;
        element->collected = true;
    }
    // deleting collectible after it has been collected
    if (element->collected)
    {
        auto it = std::find(collectibles_list.begin(), collectibles_list.end(), element);
        collectibles_list.erase(it);
    }
    // std::cout<<"Score" << score << std::endl;
    }
}

void MidMischief::show_score(){
    // SDL_Init();
    TTF_Init();                                                                              // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);                                          // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};                                                             // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = std::to_string(score);                                                           // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);            // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {944, 12, 50, 30};                                               // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}

void MidMischief::text_score()
{
    // SDL_Init();
    TTF_Init();                                                                              // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);                                          // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};                                                             // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = "Pappars collected : ";                                                                 // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);            // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {774, 12, 130, 30};                                                // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}
