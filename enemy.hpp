#include <SDL.h>
#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

class enemy : public character
{
    public:
        enemy();
        ~enemy();
        void draw();
};
