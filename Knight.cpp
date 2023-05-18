#include "Knight.h"
#include "Board.h"
using namespace std;


bool Knight::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }
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