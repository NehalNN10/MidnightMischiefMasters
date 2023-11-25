#include <iostream>
#include "Map.hpp"

Map::Map(){
    for (int i = 0; i < NUM_BLOCKS_X; ++i) {
            for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
                nodes[i][j] = MapNode(i * BLOCK_WIDTH, j * BLOCK_HEIGHT);
            }
        }

        // Connect nodes horizontally
        for (int i = 0; i < NUM_BLOCKS_X - 1; ++i) {
            for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
                nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
                nodes[(i + 1)][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
            }
        }

        // Connect nodes vertically 
        for (int i = 0; i < NUM_BLOCKS_X; i+=3) {
            for (int j = 0; j < NUM_BLOCKS_Y - 1; ++j) {
                nodes[i][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + (j + 1));
                nodes[i][j + 1].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
            }
        }
}