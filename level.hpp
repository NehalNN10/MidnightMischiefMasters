#pragma once
#include <iostream>
#include "Map.hpp"
//add scope for using position class

class Level
{

    private:
        int player1X, player1Y, player2X, player2Y, chaserX, chaserY;
        int* paperPositionsX;
        int* paperPositionsY;
        map* levelMap;
        bool completed;

    public:
        Level() = default; // to facilitate creation of dynamic array for levels
        Level(int p1X, int p1Y, int p2X, int p2Y, int cX, int cY, int* ppX, int* ppY, map* lvl);

        ~Level();

        int getPlayer1X();
        int getPlayer1Y();
        int getPlayer2X();
        int getPlayer2Y();

        int* getPapersX();
        int* getPapersY();

        void setMap(map* m);

        map* getMap();

        //TODO: implement getters for other attributes too

};