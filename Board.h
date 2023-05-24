#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;

class Square;

class Board {
private:
    Square* square;
    vector<vector<Square>> squares;

public:
    Board();
    static const int SIZE = 8;
    void initialize();

    void print() const;

    Square& get_square(int row, int col);
    const Square& get_square(int row, int col) const;

    const vector<vector<Square>>& get_board() const;

    void remove_piece(int row, int col);

    bool isKingTaken() const;

    int get_size() const; // Public getter for SIZE
};

#endif
