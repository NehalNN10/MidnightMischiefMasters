#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class fireBoy : public character // inheritance
{
    public:
        fireBoy(int x, int y); // param ctor
        ~fireBoy(); // ctor
        void draw() override; // override function
};