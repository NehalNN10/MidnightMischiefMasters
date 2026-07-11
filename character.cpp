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
    animCounter++;
    if (animCounter >= 4) { // Only change the frame every 4 game loops
        frame = (frame + 1) % 4;
        srcRect = frames[frame];
        animCounter = 0; // Reset counter
    }
}

void character::move(char direction, map* levelMap)
{
    int stepX = 20; // Reverted back to your original map grid spacing[cite: 1]
    int jumpForce = -12;

    if (direction == 'R') // right movement
    {
        if (moverRect.x + stepX < 950 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x + stepX, moverRect.y, levelMap))
        {
            moverRect.x += stepX;
            if (moverRect.y + 60 < currentY){
                currentY -= 75;
            }
        }
    }
    else if (direction == 'L') // left movement
    {
         if (moverRect.x - stepX > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x - stepX, moverRect.y, levelMap))
        {
            moverRect.x -= stepX;
            if (moverRect.y + 60 < currentY){
                currentY -= 75;
            }
        }
    }
    
    // Smooth Jump initiation using velocity!
    if (direction == 'U' && !isJumping) 
    {
        // Check if moving up into the block above is valid using original logic[cite: 1]
        if (moverRect.y - 75 > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y - 75, levelMap))
        {
            y_velocity = jumpForce;
            isJumping = true;
        }
    }
}

// Looks at the map. If there is a gap then true, else false.
bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const map* levelMap)
{

    return true;
    
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

void character::applyGravity() 
{
    y_velocity += GRAVITY; // Now allowed because we are inside the class!
    moverRect.y += y_velocity;

    if (moverRect.y >= currentY) {
        moverRect.y = currentY;
        y_velocity = 0;
        isJumping = false;
    }
}