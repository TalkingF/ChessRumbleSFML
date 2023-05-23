#include "King.h"
#include "Board.h"

King::King(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool King::legal_move(int new_row, int new_col, const Board& board) {
    if (!Piece::legal_move(new_row, new_col, board)) {
        return false;
    }
    int row_diff = new_row - row;
    int col_diff = new_col - col;
    if (abs(row_diff) <= 1 && abs(col_diff) <= 1) {
        return true;
    }

    //NO CHECKMATE RULES YET
    return false;
}

char King::get_specific_piece() {
    return 'K';
}
