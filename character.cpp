#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

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

bool character::isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const Map& map){
    int destNodeX = destinationX / Map::BLOCK_WIDTH;
    int destNodeY = destinationY / Map::BLOCK_HEIGHT;

    // Check if the destination node is connected to the current node
    const MapNode& currentNode = map.nodes[currentX / Map::BLOCK_WIDTH][currentY / Map::BLOCK_HEIGHT];

    for (int connectedNode : currentNode.connectedNodes) {
        int connectedNodeX = connectedNode / Map::NUM_BLOCKS_Y;
        int connectedNodeY = connectedNode % Map::NUM_BLOCKS_Y;

        if (destNodeX == connectedNodeX && destNodeY == connectedNodeY) {
            return true; // Valid move
        }
    }

    return false; // Invalid move
}
