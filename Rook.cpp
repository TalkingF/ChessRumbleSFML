#include "Rook.h"
#include "Board.h"

Rook::Rook(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Rook::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }

    int row_diff = new_row - get_row();
    int col_diff = new_col - get_col();

    // Rooks can only move horizontally or vertically
    if (row_diff != 0 && col_diff != 0) {
        return false;
    }

    int row_step = (row_diff > 0) ? 1 : ((row_diff < 0) ? -1 : 0);
    int col_step = (col_diff > 0) ? 1 : ((col_diff < 0) ? -1 : 0);

    int row = get_row() + row_step;
    int col = get_col() + col_step;

    while (row != new_row || col != new_col) {
        Square& currentSquare = Board::get_board().getSquare(row, col);
        if (currentSquare.getPiece() != nullptr) {
            return false;
        }
        row += row_step;
        col += col_step;
    }

    return true;
}

char Rook::get_specific_piece() {
    return 'R';
}
