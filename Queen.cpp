#include "Queen.h"
#include "Board.h"
#include "Square.h"
using namespace std;

Queen::Queen(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Queen::legal_move(int new_row, int new_col, const Board& board) {
    if (!Piece::legal_move(new_row, new_col, board)) {
        return false;
    }
int row_diff = new_row - row;
int col_diff = new_col - col;
const vector<vector<Square>>& boardData = board.get_board();

if (row_diff == 0 && col_diff != 0) {
    // Check for obstacles horizontally
    int step = col_diff > 0 ? 1 : -1;
    for (int c = col + step; c != new_col; c += step) {
        if (boardData[row][c].get_piece() != nullptr) {
            return false;
        }
    }
} else if (row_diff != 0 && col_diff == 0) {
    // Check for obstacles vertically
    int step = row_diff > 0 ? 1 : -1;
    for (int r = row + step; r != new_row; r += step) {
        if (boardData[r][col].get_piece() != nullptr) {
            return false;
        }
    }
} else if (abs(row_diff) == abs(col_diff)) {
    // Check for obstacles diagonally
    int row_step = row_diff > 0 ? 1 : -1;
    int col_step = col_diff > 0 ? 1 : -1;
    int r = row + row_step;
    int c = col + col_step;
    while (r != new_row && c != new_col) {
        if (boardData[r][c].get_piece() != nullptr) {
            return false;
        }
        r += row_step;
        c += col_step;
    }
} else {
    return false;
}

return true;
}

char Queen::get_specific_piece() {
    return 'Q';
}
