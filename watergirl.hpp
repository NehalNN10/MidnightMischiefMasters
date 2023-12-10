#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class waterGirl : public character 
{
    public:
        waterGirl();
        ~waterGirl();
        void draw();
};