#ifndef SQUARE_H
#define SQUARE_H

#include <iostram>
#include <vector>
#include "Piece.h"
using namespace std;

class Square {
private:
    Piece* piece;

public:
    Square();

    void setPiece(Piece* p);

    Piece* getPiece() const;

    void clear();
};

#endif
