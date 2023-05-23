#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Board.h"

class Knight : public Piece {
public:
    Knight(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, const Board& board) override;

    char get_specific_piece();
};

#endif