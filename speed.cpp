#include "speed.hpp"

speed::speed()
{
    x_velocity = 0;
    y_velocity = 0;
}

int* speed::get_velocity()
{
    int* vel = new int[2];
    vel[0] = x_velocity;
    vel[1] = y_velocity;
    return vel;
}

void speed::set_velocity(int x_s, int y_s)
{
    x_velocity = x_s;
    y_velocity = y_s;
}