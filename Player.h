#ifndef Player_H
#define Player_H

#include <string>
#include "Board.h"
using namespace std;

class Player {
public:
    string name;
    Board board;
    
    Player(string name);
    void setShipsManually(); 
    bool shootToOpponent(int x, int y);
    bool ifAllSunk();
};

#endif
