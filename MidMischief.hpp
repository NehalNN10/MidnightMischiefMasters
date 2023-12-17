#include <SDL.h>
#include <SDL_ttf.h>

#include "character.hpp"
#include "fireBoy.hpp"
#include "waterGirl.hpp"
#include "collectibles.hpp"
#include "collisionClass.hpp"
#include "paperOne.hpp"
#include "drawing.hpp"
#include "level.hpp"
#include "Map.hpp"

#include "vector"
#include <iostream>
#include <string>

class midMischief {

    private:
        SDL_Window *gwindow;

        // dynamically created for virual and polymorphic behaviour
        character *one; // fireboy
        character *two; // watergirl
        std::vector<collectibles*> collectiblesList;
        std::vector<collectibles*> elementsToDelete;

        char directionOne;
        char directionTwo;
        bool paused;
        int score;
        int currentLevel;
        std::vector<Level*> levels;

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
        void loadLevel(int currentLevel);
};