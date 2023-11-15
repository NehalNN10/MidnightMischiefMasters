#include <SDL.h>

class character {
    public:
        // made everything public for now
        SDL_Rect srsRect, moverRect;

        character(SDL_Rect srs, SDL_Rect mover);
        void draw();
        virtual void move() = 0;
};