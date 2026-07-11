#pragma once
#include <iostream>
#include "Map.hpp"
//add scope for using position class

// inside level.hpp
class Level
{
    private:
        int player1X, player1Y, player2X, player2Y, chaserX, chaserY;
        std::vector<int> paperPositionsX;
        std::vector<int> paperPositionsY;
        map* levelMap;

    public:
        Level() = default;
        // Update constructor to take vectors instead of int*
        Level(int p1X, int p1Y, int p2X, int p2Y, int cX, int cY, std::vector<int> ppX, std::vector<int> ppY, map* lvl);
        ~Level();

        int getPlayer1X();
        int getPlayer1Y();
        int getPlayer2X();
        int getPlayer2Y();

        // Update getters to return vectors
        std::vector<int> getPapersX();
        std::vector<int> getPapersY();

        void setMap(map* m);
        map* getMap();
        bool isCompleted();
};