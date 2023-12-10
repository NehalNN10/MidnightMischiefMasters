#pragma once
#include <vector>

class mapNode {
    public:

        int mapX, mapY;

        // For simplicity, you can store the indices of connected nodes.
        std::vector<int> connectedNodes;
        mapNode(int posX = 0, int posY = 0);
        ~mapNode();

};