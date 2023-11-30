#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "drawing.hpp"

class Score
{
    private:
        int sc = 0;

    public:
        void incScore();
        void drawScore();
};