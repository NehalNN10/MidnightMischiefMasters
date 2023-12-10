#include <iostream>
#include "mapNode.hpp"

mapNode::mapNode(int posX, int posY)
{  
    std::cout<<"mapMode Ctor Called\n";
    mapX = posX;
    mapY = posY;
}

mapNode::~mapNode()
{
    std::cout<<"mapMode Dtor Called\n";
}
