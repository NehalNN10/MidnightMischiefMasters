#include <iostream>
#include "mapNode.hpp"

// mapNode::mapNode(int posX, int posY)
// {  
//     std::cout<<"mapMode Ctor Called\n";
//     mapX = posX;
//     mapY = posY;
// }

mapNode::mapNode(int posX, int posY) : mapX(posX), mapY(posY), cost(INT_MAX), predecessor({-1, -1}) 
{
    // std::cout<<"mapNode Ctor Called\n";
}

mapNode::~mapNode()
{
    // std::cout<<"mapMode Dtor Called\n";
}
