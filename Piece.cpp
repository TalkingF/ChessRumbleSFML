#include "Piece.h"

Piece::Piece(bool is_white_, int row_, int col_) {
    colour = colour_;
    row = row_;
    col = col_;
}

bool Piece::what_colour() {
    return colour;
}

int Piece::get_row() {
    return row;
}

int Piece::get_col() {
    return col;
}

void Piece::set_position(int new_row, int new_col) {
    row = new_row;
    col = new_col;
}
