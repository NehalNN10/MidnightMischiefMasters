#include <iostream>
#include "character.hpp"

character::character()
{   
    // constructing all the variables here
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
    // dtor used for deleting all objects created in heap
    std::cout<<"character Dtor Called\n";
    delete[] frames;
    frames = nullptr;
}

bool character::operator == (const collectibles *c) // operator overloading
{   
    if (collisionClass::collisionChecker(this->moverRect, c->moverRect)) // static class function called here
        return true;
    return false;
}

// current Positions for debugging
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

void character::move(char direction, map* levelMap)
{
    if (direction == 'U' && moverRect.y ==currentY) // up and if currently on the ground
    {
        if (moverRect.y - jumpY > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y - jumpY, levelMap)) // if move is valid
        {
            moverRect.y -= 80; // change the ground if jumped
            flag = false;}
        else if (moverRect.y - 20 > 0){  
            moverRect.y -= 20;
        }

    }
    // making the character fall down if there is no ground as in a gap in map.
    if (flag && moverRect.y + jumpY < 550 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y + jumpY, levelMap))
    //if (moverRect.y + jumpY < 550)
    {
        //moverRect.y += jumpY;
        currentY += 75;
        flag = false;
    }
    //}
    if (direction == 'R') // right movement
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
    else if (direction == 'L') // left movement
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

// Looks at the map. If there is a gap then true, else false.
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
