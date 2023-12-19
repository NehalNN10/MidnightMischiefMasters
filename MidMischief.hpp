// libraries
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <iostream>
#include <string>
// all headers from different .hpp files
#include "character.hpp"
#include "fireBoy.hpp"
#include "waterGirl.hpp"
#include "collectibles.hpp"
#include "collisionClass.hpp"
#include "paperOne.hpp"
#include "drawing.hpp"
#include "level.hpp"
#include "Map.hpp"

class midMischief {

    private:
        SDL_Window *gwindow;

        // dynamically created for virual and polymorphic behaviour
        character *one; // fireboy
        character *two; // watergirl
        // vectors for collectibles and levels, polymorphic behaviour
        std::vector<collectibles*> collectiblesList;
        std::vector<Level*> levels;
        // other necc variables
        char directionOne;
        char directionTwo;
        bool paused;
        int score;
        int currentLevel;
        bool won; // if won

    public:

        midMischief(); // ctor
        ~midMischief(); // dtor
        void drawCharacters(); // drawing all chars
        void animateCharacters(); // for animations
        void moveCharacters(const Uint8* keyStates); // moving both chars simultaneously
        void applyGravity();
        bool getPaused();
        void togglePaused(bool p);
        void allCollisions(); // collision between collectibles and characters
        void showScore(); // score
        void textScore();
        void loadLevel(bool x); // different levels
        // getter setter for bool won
        bool getWon() {
            return won;
        }
        void setWon(bool a) {
            won = a;
        }
        void handleLevels();
};