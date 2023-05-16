#ifndef BISOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col);

    char get_specific_piece();
};

#endif