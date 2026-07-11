#include "level.hpp"

Level::Level(int p1X, int p1Y, int p2X, int p2Y, int cX, int cY, std::vector<int> ppX, std::vector<int> ppY, map *lvl) 
    : player1X(p1X), player1Y(p1Y), player2X(p2X), player2Y(p2Y), chaserX(cX), chaserY(cY), 
      paperPositionsX(ppX), paperPositionsY(ppY), levelMap(lvl)
{
    std::cout << "Level created" << std::endl;
}

Level::~Level()
{   
    // Vectors clean themselves up automatically! No delete[] needed.
    delete levelMap;
    levelMap = nullptr;
    std::cout << "Level destroyed!" << std::endl;
}

int Level::getPlayer1X(){ return player1X; }
int Level::getPlayer1Y(){ return player1Y; }
int Level::getPlayer2X(){ return player2X; }
int Level::getPlayer2Y(){ return player2Y; }

std::vector<int> Level::getPapersX(){ return paperPositionsX; }
std::vector<int> Level::getPapersY(){ return paperPositionsY; }

void Level::setMap(map* m){ *levelMap = *m;}
map* Level::getMap(){ return levelMap; }

bool Level::isCompleted() { return false; }