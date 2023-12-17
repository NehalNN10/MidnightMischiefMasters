#include <iostream>
#include "character.hpp"

character::character()
{
    std::cout<<"character Ctor Called\n";
}

character::~character()
{
    std::cout<<"character Dtor Called\n";
}

// draws character
void character::draw()
{
    // implemenatation in derived classes
}

// changes animation of character
void character::animation()
{
    frame = (frame + 1) % 4;
    srcRect = frames[frame];
}

bool character::jump_available()
{
    return character::moverRect.y + character::moverRect.h >= 450;
}

void character::move(char direction, map* levelMap)
{
    if (direction == 'U' && moverRect.y ==currentY)
    {
        if (moverRect.y - jumpY > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y - jumpY, levelMap))
        //if (moverRect.y - jumpY > 0)
            {// moverRect.y -= jumpY;
            //gravity = -80;
            moverRect.y -= 80;
            flag = false;}
        else if (moverRect.y - 20 > 0){
            moverRect.y -= 20;
        }

    }
    //else if (direction == 'D')
    //{
        if (flag && moverRect.y + jumpY < 550 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y + jumpY, levelMap))
        //if (moverRect.y + jumpY < 550)
        {
            //moverRect.y += jumpY;
            currentY += 75;
            flag = false;
        }
    //}
    if (direction == 'R')
    {
        if (moverRect.x + jumpX < 950 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x + jumpX, moverRect.y, levelMap))
        //if (moverRect.x + jumpX < 950)
            {moverRect.x += jumpX;
            flag = true;
                if (moverRect.y + 60 < currentY){
                    currentY -= 75;
                }
            }
    }
    else if (direction == 'L')
    {
         if (moverRect.x - jumpX > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x - jumpX, moverRect.y, levelMap))
        //if (moverRect.x - jumpX > 0)
            {moverRect.x -= jumpX;
            flag = true;
                if (moverRect.y + 60 < currentY){
                    currentY -= 75;
                }}
    }
}

bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const map* levelMap)
{
    int destNodeX = destinationX / levelMap->BLOCK_WIDTH;
    int destNodeY = destinationY / levelMap->BLOCK_HEIGHT;

    int currentNodeX = currentX / levelMap->BLOCK_WIDTH;
    int currentNodeY = currentY / levelMap->BLOCK_HEIGHT;

    // Check if the destination node is connected to the current node
    const mapNode &currentNode = levelMap->nodes[currentNodeX][currentNodeY];

    // std::cout << "Current Node: (" << currentNodeX << ", " << currentNodeY << ")" << std::endl;
    // std::cout << "Destination Node: (" << destNodeX << ", " << destNodeY << ")" << std::endl;

    for (int connectedNode : currentNode.connectedNodes)
    {
        int connectedNodeX = connectedNode / levelMap->NUM_BLOCKS_Y;
        int connectedNodeY = connectedNode % levelMap->NUM_BLOCKS_Y;

        if (destNodeX == connectedNodeX && destNodeY == connectedNodeY)
        {
            return true; // Valid move
        }
    }

    return false; // Invalid move
}
