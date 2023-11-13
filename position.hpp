#pragma once

class position
{

    private:
        int x_coord;
        int y_coord;

    public:

        position();

        int* get_coord();

        void set_coord(int x, int y);

};