#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"

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
