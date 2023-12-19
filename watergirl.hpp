#include <SDL.h>
#include "character.hpp"
#include "drawing.hpp"

class waterGirl : public character // inheritance
{
    public:
        waterGirl(int x, int y); // param ctor
        ~waterGirl(); // dtor
        void draw() override; // virtual function in base class
};