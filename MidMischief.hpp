#include <SDL.h>
#include <SDL_ttf.h>

#include "character.hpp"
#include "fireBoy.hpp"
#include "waterGirl.hpp"
#include "collectibles.hpp"
#include "collisionClass.hpp"
#include "paperOne.hpp"

#include "vector"
#include <iostream>
#include <string>

class midMischief {

    private:
        SDL_Window *gwindow;

        // dynamically created for virual and polymorphic behaviour
        character *one;
        character *two;
        std::vector<collectibles*> collectiblesList;

        char directionOne;
        char directionTwo;
        bool paused;
        int score;

    public:

        midMischief();
        ~midMischief();
        void drawCharacters();
        void animateCharacters();
        void moveCharacters(const Uint8* keyStates);
        void applyGravity();
        bool getPaused();
        void togglePaused(bool p);
        void allCollisions();
        void showScore();
        void textScore();
};