#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, ChessBoard& board) override;

    char get_specific_piece();
};

#endif