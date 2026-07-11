#pragma once
#include "mapNode.hpp"

class map {
public:
    static const int SCREEN_WIDTH = 1200;  // From your original setup
    static const int SCREEN_HEIGHT = 900; // From your original setup

    // Upgrade to clean square dimensions!
    static const int BLOCK_WIDTH = 40;   // Changed from 20[cite: 1]
    static const int BLOCK_HEIGHT = 40;  // Changed from 75[cite: 1]

    // This dynamically recalculates your grid size based on the screen size
    static const int NUM_BLOCKS_X = SCREEN_WIDTH / BLOCK_WIDTH;   // 1000 / 40 = 25 blocks wide
    static const int NUM_BLOCKS_Y = SCREEN_HEIGHT / BLOCK_HEIGHT; // 600 / 40 = 15 blocks high

    // Keep the node array[cite: 1]
    mapNode nodes[NUM_BLOCKS_X][NUM_BLOCKS_Y];

    // ctor & dtor
    map(int* gaps);
    ~map();
};