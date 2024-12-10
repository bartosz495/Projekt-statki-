#include "Player.h"
#include <iostream>
#include <vector>

Player::Player(std::string name) {
    this->name = name;
}

void Player::setShipsManually() {
    std::vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; 
    for (int i = 0; i < ships.size(); i++) {
        bool set = false;
        while (!set) {
            int x, y;
            char orientation;
            std::cout << "Ustaw statek o dlugosci " << ships[i] << " (wpisz wspolrzedne x, y oraz orientacje [POZIOMO(H)/PIONOWO(V)]): ";
            std::cin >> x >> y >> orientation;

            
            if (board.setShip(x, y, ships[i], orientation)) {
                set = true;
                std::cout << "Statek ustawiony pomyslnie!\n";
                board.showBoard(false);  
            } else {
                std::cout << "Nie udalo się ustawic statku. Sprobuj ponownie.\n";
            }
        }
    }
}

bool Player::shootToOpponent(int x, int y) {
    return board.shoot(x, y);
}

bool Player::ifAllSunk() {
    return board.checkIfAllSunk();
}
