#ifndef BOARD_H
#define BOARD_H

#include <iostram>
#include <vector>
#include "Square.h"
using namespace std;


class Board {
private:
    static const int SIZE = 8;
    vector<vector<Square>> squares;

public:
    Board();

    void initialize();

    void print() const;

    Square& getSquare(int row, int col);
};

#endif
