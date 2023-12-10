#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class fireBoy : public character 
{
    public:
        fireBoy();
        ~fireBoy();
        void draw();
};