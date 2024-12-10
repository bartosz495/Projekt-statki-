#ifndef Board_H
#define Board_H

class Board {
public:
    char board[10][10];
    
    Board();
    void showBoard(bool oppView = false);
    bool checkArea(int x, int y, int lenght, char orientation);
    bool setShip(int x, int y, int lenght, char orientation);
    bool shoot(int x, int y);
    bool checkIfAllSunk();
};

#endif