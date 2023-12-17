#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include "map.hpp"

// map::map(){
//     std::cout<<"map Ctor Called\n";
//     for (int i = 0; i < NUM_BLOCKS_X; ++i) {
//             for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
//                 nodes[i][j] = mapNode(i * BLOCK_WIDTH, j * BLOCK_HEIGHT);
//             }
//         }
//         // Connect nodes horizontally
//         for (int i = 0; i < NUM_BLOCKS_X - 1; i++) {
//             for (int j = 0; j < NUM_BLOCKS_Y; j++) {
//                 nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
//                 nodes[(i + 1)][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
//             }
//         }

//         // Connect nodes vertically
//         int arr[NUM_BLOCKS_Y] = {0, 3, 23, 39, 19, 10, 10, 10};


//         for (int j = 0; j < NUM_BLOCKS_Y - 1; j++) {
//             nodes[arr[j]][j].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + (j + 1));
//             nodes[arr[j]][j + 1].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + j);
//         }  
// }
map::map() {
    std::cout << "map Ctor Called\n";
    for (int i = 0; i < NUM_BLOCKS_X; ++i) {
        for (int j = 0; j < NUM_BLOCKS_Y; ++j) {
            nodes[i][j] = mapNode(i * BLOCK_WIDTH, j * BLOCK_HEIGHT);
        }
    }

    // // Connect nodes horizontally
    // for (int i = 0; i < NUM_BLOCKS_X - 1; i++) {
    //     for (int j = 0; j < NUM_BLOCKS_Y; j++) {
    //         nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
    //         nodes[i + 1][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
    //     }
    // }

    // // Connect nodes vertically using the provided array
    // int arr[NUM_BLOCKS_Y] = {0, 3, 23, 39, 19, 10, 10, 10};

    // for (int j = 0; j < NUM_BLOCKS_Y - 1; j++) {
    //     nodes[arr[j]][j].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + (j + 1));
    //     nodes[arr[j]][j + 1].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + j);
    // }
    // Connect nodes horizontally
    for (int i = 0; i < NUM_BLOCKS_X - 1; i++) {
        for (int j = 0; j < NUM_BLOCKS_Y; j++) {
            nodes[i][j].connectedNodes.push_back((i + 1) * NUM_BLOCKS_Y + j);
            nodes[i + 1][j].connectedNodes.push_back(i * NUM_BLOCKS_Y + j);
        }
    }

    // Connect nodes vertically
    int arr[NUM_BLOCKS_Y] = {0, 3, 23, 39, 19, 10, 10, 10};
    for (int j = 0; j < NUM_BLOCKS_Y - 1; j++) {
        nodes[arr[j]][j].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + (j + 1));
        nodes[arr[j]][j + 1].connectedNodes.push_back(arr[j] * NUM_BLOCKS_Y + j);
    }
}


map::~map()
{
    std::cout<<"map Dtor Called\n";
}

// void map::dijkstra(int srcX, int srcY, int destX, int destY) {
//     const int inf = INT_MAX;
//     std::vector<std::vector<bool>> visited(NUM_BLOCKS_X, std::vector<bool>(NUM_BLOCKS_Y, false));

//     nodes[srcX][srcY].cost = 0;

//     using pii = std::pair<int, std::pair<int, int>>;
//     std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
//     minHeap.push({0, {srcX, srcY}});

//     while (!minHeap.empty()) {
//         int tempX = minHeap.top().second.first;
//         int tempY = minHeap.top().second.second;
//         minHeap.pop();

//         if (visited[tempX][tempY]) {
//             continue;
//         }

//         visited[tempX][tempY] = true;

//         // for (int neighborIndex : nodes[tempX][tempY].connectedNodes) {
//         //     int neighborX = neighborIndex / NUM_BLOCKS_Y;
//         //     int neighborY = neighborIndex % NUM_BLOCKS_Y;
//         //     int weight = 1;

//         //     int cost = nodes[tempX][tempY].cost + weight;

//         //     if (cost < nodes[neighborX][neighborY].cost) {
//         //         nodes[neighborX][neighborY].cost = cost;
//         //         nodes[neighborX][neighborY].predecessor = {tempX, tempY};  // Update predecessor
//         //         minHeap.push({cost, {neighborX, neighborY}});
//         //     }
//         // }
//             for (int neighborIndex : nodes[tempX][tempY].connectedNodes) {
//                 int neighborX = neighborIndex / NUM_BLOCKS_Y;
//                 int neighborY = neighborIndex % NUM_BLOCKS_Y;
//                 int weight = 1;

//                 int cost = nodes[tempX][tempY].cost + weight;

//                 if (cost < nodes[neighborX][neighborY].cost) {
//                     nodes[neighborX][neighborY].cost = cost;
//                     nodes[neighborX][neighborY].predecessor = {tempX, tempY};  // Update predecessor
//                     minHeap.push({cost, {neighborX, neighborY}});
//                 }
//             }
//     }
// // }
// void map::dijkstra(int srcX, int srcY, int destX, int destY) {
//     const int inf = INT_MAX;
//     std::vector<std::vector<bool>> visited(NUM_BLOCKS_X, std::vector<bool>(NUM_BLOCKS_Y, false));

//     nodes[srcX][srcY].cost = 0;

//     using pii = std::pair<int, std::pair<int, int>>;
//     std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
//     minHeap.push({0, {srcX, srcY}});

//     while (!minHeap.empty()) {
//         int tempX = minHeap.top().second.first;
//         int tempY = minHeap.top().second.second;
//         minHeap.pop();

//         if (visited[tempX][tempY]) {
//             continue;
//         }

//         visited[tempX][tempY] = true;

//         for (int i = 0; i < nodes[tempX][tempY].connectedNodes.size(); i++) {
//             int neighborIndex = nodes[tempX][tempY].connectedNodes[i];
//             int neighborX = neighborIndex / NUM_BLOCKS_Y;
//             int neighborY = neighborIndex % NUM_BLOCKS_Y;
//             int weight = 1;

//             int cost = nodes[tempX][tempY].cost + weight;

//             if (cost < nodes[neighborX][neighborY].cost) {
//                 nodes[neighborX][neighborY].cost = cost;
//                 nodes[neighborX][neighborY].predecessor = {tempX, tempY};
//                 minHeap.push({cost, {neighborX, neighborY}});
//             }
//         }
//     }
// }
void map::dijkstra(int srcX, int srcY, int destX, int destY) {
    const int inf = INT_MAX;
    std::vector<std::vector<bool>> visited(NUM_BLOCKS_X, std::vector<bool>(NUM_BLOCKS_Y, false));

    nodes[srcX][srcY].cost = 0;

    using pii = std::pair<int, std::pair<int, int>>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
    minHeap.push({0, {srcX, srcY}});
    while (!minHeap.empty()) {
        int tempX = minHeap.top().second.first;
        int tempY = minHeap.top().second.second;
        minHeap.pop();

        if (visited[tempX][tempY]) {
            continue;
        }

        visited[tempX][tempY] = true;

        for (int i = 0; i < nodes[tempX][tempY].connectedNodes.size(); i++) {
            int neighborIndex = nodes[tempX][tempY].connectedNodes[i];
            int neighborX = neighborIndex / NUM_BLOCKS_Y;
            int neighborY = neighborIndex % NUM_BLOCKS_Y;
            int weight = 1;

    // while (!minHeap.empty()) {
    //     int tempX = minHeap.top().second.first;
    //     int tempY = minHeap.top().second.second;
    //     minHeap.pop();

    //     if (visited[tempX][tempY]) {
    //         continue;
    //     }

    //     visited[tempX][tempY] = true;

    //     for (int i = 0; i < nodes[tempX][tempY].connectedNodes.size(); i++) {
    //         int neighborIndex = nodes[tempX][tempY].connectedNodes[i];
    //         int neighborX = neighborIndex / NUM_BLOCKS_Y;
    //         int neighborY = neighborIndex % NUM_BLOCKS_Y;
    //         int weight = 1;

            int cost = nodes[tempX][tempY].cost + weight;

            if (cost < nodes[neighborX][neighborY].cost) {
                nodes[neighborX][neighborY].cost = cost;
                nodes[neighborX][neighborY].predecessor = {tempX, tempY};
                minHeap.push({cost, {neighborX, neighborY}});
            }
        }
    }
}

std::vector<mapNode> map::printPath(int destX, int destY) {
    std::vector<mapNode> result;
    std::pair<int, int> current = {destX, destY};
    std::cout<<"\nstarting:"<<std::endl;
    while (current.first != -1 && current.second != -1) {
        result.push_back(mapNode(current.first, current.second));
        if (current != nodes[current.first][current.second].predecessor) {
        std::cout << "(" << current.first << ", " << current.second << ")";

            std::cout << " <- ";
        }
        current = nodes[current.first][current.second].predecessor;
    }
    return result;
}

// std::vector<mapNode> map::printPath(int destX, int destY) {
    
//     std::vector <mapNode> result;
//     std::pair<int, int> current = {destX, destY};

//     // while (current.first != -1 && current.second != -1) {
//     //     // std::cout << "(" << current.first << ", " << current.second << ")";
//     //     result.push_back(mapNode(current.first, current.second));
//     //     if (current != nodes[current.first][current.second].predecessor) {
//     //         std::cout << " <- ";
//     //     }
//     //     current = nodes[current.first][current.second].predecessor;
//     // }
//     while (current.first != -1 || current.second != -1) {
//     result.push_back(mapNode(current.first, current.second));
//     if (current != nodes[current.first][current.second].predecessor) {
//         std::cout << " <- ";
//     }
//     current = nodes[current.first][current.second].predecessor;
// }   
//     return result;
// }