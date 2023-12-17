#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class waterGirl : public character 
{
    public:
        waterGirl(int x, int y);
        ~waterGirl();
        void draw();
};