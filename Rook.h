#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Board.h"

class Rook : public Piece {
public:
    Rook(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, const Board& board) override;

    char get_specific_piece();
};

#endif
