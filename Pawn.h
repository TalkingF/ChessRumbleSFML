#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Square.h"
//Header file for a pawn class that inherits from the piece class.

class Pawn : public Piece {
public:
    Pawn(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, const Board& board) override;

    char get_specific_piece();
};

#endif