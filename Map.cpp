#include <iostream>
#include "map.hpp"

map::map(int* gaps){ 
    std::cout<<"map Ctor Called\n";
    for (int i = 0; i < NUM_BLOCKS_X; ++i) {
        for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
            nodes[i][j] = mapNode(i * BLOCK_WIDTH, j * BLOCK_HEIGHT);
        }
    }

    // Connect nodes horizontally
    for (int i = 0; i < NUM_BLOCKS_X - 1; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
            nodes[(i + 1)][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
        }
    }

    // FIX: Cap this at 7 steps because gaps array size is only 8!
    // This stops the out-of-bounds pointer crash completely.
    int maxGaps = (NUM_BLOCKS_Y - 1 < 7) ? NUM_BLOCKS_Y - 1 : 7;
    for (int j = 0; j < maxGaps; j++) {
        nodes[gaps[j]][j].connectedNodes.push_back(gaps[j] * NUM_BLOCKS_Y + (j + 1));
        nodes[gaps[j]][j + 1].connectedNodes.push_back(gaps[j] * NUM_BLOCKS_Y + j);
    }  
}

map::~map()
{
    std::cout<<"map Dtor Called\n";
}