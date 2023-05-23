#include "Piece.h"
#include "Square.h"

Piece::Piece(bool colour_, int row_, int col_) {
    colour = colour_;
    row = row_;
    col = col_;
}

bool Piece::get_colour() {
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

bool Piece::legal_move(int new_row, int new_col, const Board& board){
    // Check if the new position is within the bounds of the chessboard
    if (new_row < 0 || new_row >= 8 || new_col < 0 || new_col >= 8) {
        return false; // The move is out of bounds
    }
    return true; // The move is valid
}
