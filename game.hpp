#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <SDL_mixer.h> //for playing game music
#include <time.h>

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assetOne=NULL;
    SDL_Texture* assetTwo=NULL;

    SDL_Texture* paperOne=NULL;

    //for game music
    Mix_Music *gMusic = NULL;
    Mix_Music *winMusic = NULL;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    
    // different screens implemented here
    bool gameStart();
    bool winScreen();
    bool gamePause();
    bool controls();
    bool howToPlay();
    bool credits();
};