#pragma once

class speed
{
    private:
        int x_velocity;
        int y_velocity;

    public:
        speed();
        int* get_velocity();
        void set_velocity(int x_s, int y_s);
};