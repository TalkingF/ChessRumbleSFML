#include "Queen.h"

Queen::Queen(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Queen::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }
    int row_diff = new_row - row_;
    int col_diff = new_col - col_;
    if (row_diff == 0 || col_diff == 0) { // Rook-like move
        int step = row_diff == 0 ? col_diff / abs(col_diff) : row_diff / abs(row_diff);
        int i = row_ + step;
        while (i != new_row) {
            if (Board::get_board().get_piece(i, col_) != nullptr) {
                return false;
            }
            i += step;
        }
        int j = col_ + step;
        while (j != new_col) {
            if (Board::get_board().get_piece(row_, j) != nullptr) {
                return false;
            }
            j += step;
        }
    } else if (abs(row_diff) == abs(col_diff)) { // Bishop-like move
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
    } else {
        return false;
    }
    return true;
}

char Queen::get_specific_piece() {
    return 'Q';
}
