#pragma once
#include "mapNode.hpp"

class map {
public:
    // Screen dimensions
    static const int SCREEN_WIDTH = 1000;
    static const int SCREEN_HEIGHT = 600;

    // Dimensions of each block or node
    static const int BLOCK_WIDTH = 20;
    static const int BLOCK_HEIGHT = 75;

    // Number of blocks in x and y directions
    static const int NUM_BLOCKS_X = SCREEN_WIDTH / BLOCK_WIDTH;
    static const int NUM_BLOCKS_Y = SCREEN_HEIGHT / BLOCK_HEIGHT;

    // 2D array to store nodes
    mapNode nodes[NUM_BLOCKS_X][NUM_BLOCKS_Y];

    map();
    ~map();
    void foo();
};