#include "score.hpp"


void Score::incScore(){ sc++;}
void Score::drawScore()
{
    // SDL_Init();
    TTF_Init();                                                                              // Initializes SDL_TTF for displaying text in
    TTF_Font *font = TTF_OpenFont("Assets/arial.ttf", 24);                                          // Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0};                                                             // This is the texts color that can be changed using RGB values from 0 to 255.
    std::string tmp = std::to_string(sc);                                                 // converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color);            // A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfacemessage); // Converts into texture that can be displayed
    SDL_Rect Message_rect = {110, 50, 30, 30};                                               // create a rect for it
    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}