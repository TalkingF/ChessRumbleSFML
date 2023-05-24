#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "ChessBoard.h"

class Bishop : public Piece {
public:
    Bishop(bool colour_, int row_, int col_);

    bool legal_move(int new_row, int new_col, ChessBoard& board) override;

    char get_specific_piece();
};

#endif