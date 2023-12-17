#pragma once
#include <vector>

class mapNode {
    private:
        int mapX, mapY;
        
    public:
        // For simplicity, you can store the indices of connected nodes.
        std::vector<int> connectedNodes;
        int cost;
        std::pair<int, int> predecessor;  // Added for predecessor information
        mapNode(int posX = 0, int posY = 0);
        ~mapNode();
        
        friend std::ostream& operator<<(std::ostream& out, const mapNode& node) 
        {
            out<<"( "<<node.mapX<<" "<<node.mapY<<" )";
            return out;
        }
        int getX() const { return mapX; }
        int getY() const { return mapY; }
};
