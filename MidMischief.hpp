#include <SDL.h>
#include <SDL_ttf.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"
#include "collectibles.hpp"
#include "collisionCheck.hpp"
// #include "score.hpp"
#include "paper1.hpp"
#include "vector"
#include <iostream>
#include <string>

class MidMischief {

    private:
        SDL_Window *gwindow;
        // dynamically created for virual and polymorphic behaviour
        character *one;
        character *two;
        // collectibles *first;
        std::vector<collectibles*> collectibles_list;
        char direction_1;
        char direction_2;
        bool paused;
        int score;

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        void movechars(const Uint8* keystates);
        void apply_gravity();
        bool getpaused();
        void toggle_paused(bool p);
        void allCollisions();
        void show_score();
        void text_score();
};