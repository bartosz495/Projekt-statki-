#include "Board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '~';
        }
    }
}

void Board::showBoard(bool oppView) {
    std::cout << "   ";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            if (oppView && board[i][j] == 'O') {
                std::cout << "~ ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
bool Board::checkArea(int x, int y, int lenght, char orientation) {
    if (orientation == 'H') { // Poziomo
        for (int i = -1; i <= lenght; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[ny][nx] != '~') {
                    return false;
                }
            }
        }
    } else if (orientation == 'V') { // Pionowo
        for (int i = -1; i <= lenght; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + j;
                int ny = y + i;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[ny][nx] != '~') {
                    return false;
                }
            }
        }
    }
    return true;
}


bool Board::setShip(int x, int y, int lenght, char orientation) {
    // Sprawdź, czy statek zmieści się na planszy
    if ((orientation == 'H' && (x + lenght - 1) >= 10) || (orientation == 'V' && (y + lenght - 1) >= 10)) {
        return false;
    }

    // Sprawdź, czy okolice są wolne
    if (!checkArea(x, y, lenght, orientation)) {
        return false;
    }

    // Ustaw statek
    if (orientation == 'H') {
        for (int i = 0; i < lenght; i++) {
            board[y][x + i] = 'O';
        }
    } else if (orientation == 'V') {
        for (int i = 0; i < lenght; i++) {
            board[y + i][x] = 'O';
        }
    }

    return true;
}


bool Board::shoot(int x, int y) {
    if (board[y][x] == 'O') {
        board[y][x] = 'X';
        std::cout << "Trafiony!\n";
        return true;
    } else if (board[y][x] == '~') {
        board[y][x] = 'P';
        std::cout << "Pudlo!\n";
        return false;
    } else {
        std::cout << "To pole zostalo już trafione! Tracisz ture.\n";
        return false;
    }
}

bool Board::checkIfAllSunk() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 'O') {
                return false;
            }
        }
    }
    return true;
}
