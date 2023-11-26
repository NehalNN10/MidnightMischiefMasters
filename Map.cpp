#include <iostream>
#include "Map.hpp"

Map::Map(){
    for (int i = 0; i < NUM_BLOCKS_X; ++i) {
            for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
                nodes[i][j] = MapNode(i * BLOCK_WIDTH, j * BLOCK_HEIGHT);
            }
        }

        // Connect nodes horizontally
        for (int i = 0; i < NUM_BLOCKS_X - 1; i++) {
            for (int j = 0; j < NUM_BLOCKS_Y; j++) {
                nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
                nodes[(i + 1)][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
            }
        }

        // Connect nodes vertically
        int arr[NUM_BLOCKS_Y] = {0, 2, 14, 1, 10, 6, 25, 4, 9, 17, 3, 23, 11, 7, 15, 5, 12, 22, 28, 19, 8, 27, 13, 24, 26, 18, 29, 21, 16, 20};


        for (int j = 0; j < NUM_BLOCKS_Y - 1; j++) {
            nodes[arr[j]][j].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + (j + 1));
            nodes[arr[j]][j + 1].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + j);
        }
        
}