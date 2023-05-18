#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col);

    char get_specific_piece();
};

#endif
