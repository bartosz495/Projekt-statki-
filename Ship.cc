#include "Ship.h"

Ship::Ship(int lenght) : lenght(lenght) {}

void Ship::addTail(int x, int y) {
    tails.push_back(std::make_pair(x, y));
}
