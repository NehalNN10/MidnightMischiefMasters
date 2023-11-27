#pragma once
#include <vector>

class MapNode {
public:
    int x, y;

    // For simplicity, you can store the indices of connected nodes.
    std::vector<int> connectedNodes;

    MapNode(int xPos = 0, int yPos = 0);
};