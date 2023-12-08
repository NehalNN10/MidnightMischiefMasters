#include <iostream>
#include "character.hpp"
#include "drawing.hpp"
//graph
// draws character
void character::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

// changes animation of character
void character::animation()
{
    frame = (frame + 1) % 4;
    srcRect = frames[frame];
}

<<<<<<< Updated upstream
bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const Map& map){
=======
void character::move(char direction)
{
    if (direction == 'U' && moverRect.y == currentY)
    {
        if (moverRect.y - y_jump > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y - y_jump, graph)){
        //if (moverRect.y - y_jump > 0)
            moverRect.y -= 85;
            flag = false;}
            //gravity = -23;
        else if (moverRect.y - 20 > 0){
            moverRect.y -= 20;
        }

    }
    //else if (direction == 'D')
    //{
        if (flag && moverRect.y + y_jump < 550 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y + y_jump, graph))
        //if (moverRect.y + y_jump < 550)
            {
            currentY += 75;
            flag = false;
            //moverRect.y += y_jump;
            }
    //}
    if (direction == 'R')
    {
        if (moverRect.x + x_jump < 950 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x + x_jump, moverRect.y, graph))
        //if (moverRect.x + x_jump < 950)
            {
                moverRect.x += x_jump;
                flag = true;
                if (moverRect.y + 60 < currentY){
                    currentY -= 75;
                }
            }
    }
    else if (direction == 'L')
    {
        if (moverRect.x - x_jump > 0 && character::isMoveValid(moverRect.x, moverRect.y, moverRect.x - x_jump, moverRect.y, graph))
        //if (moverRect.x - x_jump > 0)
            {
                moverRect.x -= x_jump;
                flag = true;
                if (moverRect.y + 60 < currentY){
                    currentY -= 75;
                }
                }
    }
}

bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const Map &map)
{
>>>>>>> Stashed changes
    int destNodeX = destinationX / Map::BLOCK_WIDTH;
    int destNodeY = destinationY / Map::BLOCK_HEIGHT;

    int currentNodeX = currentX / Map::BLOCK_WIDTH;
    int currentNodeY = currentY / Map::BLOCK_HEIGHT;

    // Check if the destination node is connected to the current node
    const MapNode& currentNode = map.nodes[currentNodeX][currentNodeY];

    //std::cout << "Current Node: (" << currentNodeX << ", " << currentNodeY << ")" << std::endl;
    //std::cout << "Destination Node: (" << destNodeX << ", " << destNodeY << ")" << std::endl;


    for (int connectedNode : currentNode.connectedNodes) {
        int connectedNodeX = connectedNode / Map::NUM_BLOCKS_Y;
        int connectedNodeY = connectedNode % Map::NUM_BLOCKS_Y;

        if (destNodeX == connectedNodeX && destNodeY == connectedNodeY) {
            return true; // Valid move
        }
    }

    return false; // Invalid move
}
