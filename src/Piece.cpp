#include <iostream>
#include "Piece.h"

Piece::Piece(bool is_white_, int row_, int col_) {
    colour = is_white_;
    row = row_;
    col = col_;
}

bool Piece::get_Colour() {
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