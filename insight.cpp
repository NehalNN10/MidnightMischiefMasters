#include "insight.hpp"
#include "mover.hpp"
#include <vector>

// class charachter{
//     public:
//     vector <int> src;
//     vector <int> mover;
//     charachter(vector <int> s, vector <int> m) : src(s), mover(m){}
//     vector<int> srcRect(){
//         return src;
//     }
//     vector<int> moverRect(){
//         return mover;
//     }
// };

void makeMove(string direction){
    if (direction == "East"){
        moveEast();
    }
    else if (direction == "West"){
        moveWest();
    }
    else if (direction == "North"){
        moveNorth();
    }
    else if (direction == "South"){
        moveSouth();
    }
}
