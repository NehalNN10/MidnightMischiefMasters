#include <iostream>
#include "mapNode.hpp"

mapNode::mapNode(int posX, int posY)
{  
    // std::cout<<"mapNode Ctor Called\n";
    mapX = posX;
    mapY = posY;
}

mapNode::~mapNode()
{
    // std::cout<<"mapNode Dtor Called\n";
}
