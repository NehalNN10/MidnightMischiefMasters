#include <iostream>
#include "character.hpp"

character::character()
{
    std::cout<<"character Ctor Called\n";
    flag = true;
    jumpX = 20;
    jumpY = 75;
    gravity = 0;
    frames = new SDL_Rect[4];
    currentY = 400;
}

character::~character()
{
    std::cout<<"character Dtor Called\n";
    delete[] frames;
    frames = nullptr;
}

// current Positions 
void character::printCurrentPosition()
{
    std::cout<<"current x: "<<moverRect.x;
    std::cout<<"current y: "<<moverRect.y;
    std::cout<<"\n";
}

// draws character
void character::draw()
{
    // implementation in derived classes
}

// changes animation of character
void character::animation()
{
    frame = (frame + 1) % 4;
    srcRect = frames[frame];
}

void character::move(char direction)
{
    if (direction == 'U' && moverRect.y ==currentY)
    {
        if (moverRect.y - jumpY > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y - jumpY, graph))
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
        if (flag && moverRect.y + jumpY < 550 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y + jumpY, graph))
        //if (moverRect.y + jumpY < 550)
        {
            //moverRect.y += jumpY;
            currentY += 75;
            flag = false;
        }
    //}
    if (direction == 'R')
    {
        if (moverRect.x + jumpX < 950 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x + jumpX, moverRect.y, graph))
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
         if (moverRect.x - jumpX > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x - jumpX, moverRect.y, graph))
        //if (moverRect.x - jumpX > 0)
            {moverRect.x -= jumpX;
            flag = true;
                if (moverRect.y + 60 < currentY){
                    currentY -= 75;
                }}
    }
}

bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const map &map)
{
    int destNodeX = destinationX / map::BLOCK_WIDTH;
    int destNodeY = destinationY / map::BLOCK_HEIGHT;

    int currentNodeX = currentX / map::BLOCK_WIDTH;
    int currentNodeY = currentY / map::BLOCK_HEIGHT;

    // std::cout<<"destX: "<<destNodeX<<"destY: "<<destNodeY<<std::endl;
    // std::cout<<"currentNodeX:"<<currentNodeX<<"currentNodeY:"<<currentNodeY<<std::endl;

    // Check if the destination node is connected to the current node
    const mapNode &currentNode = map.nodes[currentNodeX][currentNodeY];

    // std::cout << "Current Node: (" << currentNodeX << ", " << currentNodeY << ")" << std::endl;
    // std::cout << "Destination Node: (" << destNodeX << ", " << destNodeY << ")" << std::endl;

    for (int connectedNode : currentNode.connectedNodes)
    {
        int connectedNodeX = connectedNode / map::NUM_BLOCKS_Y;
        int connectedNodeY = connectedNode % map::NUM_BLOCKS_Y;

        // std::cout<<"connectedx"<<connectedNodeX<<" connectedy"<<connectedNodeY<<std::endl;

        if (destNodeX == connectedNodeX && destNodeY == connectedNodeY)
        {
            return true; // Valid move
        }
    }
    return false; // Invalid move
}
