#include "Rook.h"

Rook::Rook(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Rook::legal_move(int new_row, int new_col) {
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }
    if (new_row == row || new_col == col) {
        return true;
    }
    return false;

    //NOTE: doesn't include castling. That's damn hard. Ill figure it out later.
}

char Rook::get_specific_piece() {
    return 'R';
}