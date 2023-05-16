#include "Bishop.h"

Bishop::Bishop(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}


bool Bishop::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }
    int row_diff = new_row - row_;
    int col_diff = new_col - col_;
    if (abs(row_diff) != abs(col_diff)) {
        return false;
    }
    int row_step = row_diff > 0 ? 1 : -1;
    int col_step = col_diff > 0 ? 1 : -1;
    int row = row_ + row_step;
    int col = col_ + col_step;
    while (row != new_row && col != new_col) {
        if (Board::get_board().get_piece(row, col) != nullptr) {
            return false;
        }
        row += row_step;
        col += col_step;
    }
    return true;
}


char Bishop::get_specific_piece() {
    return 'B';
}