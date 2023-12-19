#pragma once
#include <vector>

class mapNode {
    private:
        // coods of that map Node
        int mapX, mapY;
        
    public:
        // For simplicity, you can store the indices of connected nodes.
        std::vector<int> connectedNodes;
        
        mapNode(int posX = 0, int posY = 0); // ctor
        ~mapNode(); // dtor

};