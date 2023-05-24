#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, ChessBoard& board) override;

    char get_specific_piece();
};

#endif