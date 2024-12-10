#ifndef Ship_H
#define Ship_H

#include <vector>

class Ship {
public:
    int lenght;
    std::vector<std::pair<int, int>> tails; // Lista pól, które zajmuje statek
    
    Ship(int lenght);
    void addTail(int x, int y);
};

#endif
