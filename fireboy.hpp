#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class fireBoy : public character 
{
    public:
        fireBoy(int x, int y);
        ~fireBoy();
        void draw();
};