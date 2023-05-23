#include "Knight.h"
#include "ChessBoard.h"
using namespace std;

Knight::Knight(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Knight::legal_move(int new_row, int new_col) {

    int row_diff = abs(new_row - row);
    int col_diff = abs(new_col - col);
    if ((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2)) {
        return true;
    }
    return false;
}

char Knight::get_specific_piece() {
    return 'N';
}