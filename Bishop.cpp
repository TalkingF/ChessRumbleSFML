#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Bishop::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }

    Board board;
    const vector<vector<Square>>& boardData = board.get_board();
    const Square& currentSquare = boardData[row][col];

    int row_diff = new_row - get_row();
    int col_diff = new_col - get_col();
    if (abs(row_diff) != abs(col_diff)) {
        return false;
    }

    int row_step = (row_diff > 0) ? 1 : -1;
    int col_step = (col_diff > 0) ? 1 : -1;
    int row = get_row() + row_step;
    int col = get_col() + col_step;

    while (row != new_row && col != new_col) {
        if (currentSquare.getPiece() != nullptr) {
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
