#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Pawn::legal_move(int new_row, int new_col) {
    int move_direction = (colour) ? -1 : 1;
    if (new_col == col && new_row == row + move_direction) {
        // Move one space forward.
        return true;
    }
    if (new_col == col && new_row == row + 2*move_direction && row == (colour ? 6 : 1)) {
        // Move two spaces forward from starting position
        return true;
    }

    //NOTE: THIS CLASS DOES NOT ACCOUNT FOR TAKING A PIECE. FOR THAT WE NEED THE BOARDS MEMORY (probably need pointers)
    //NOTE: NO EN PASSANT EITHER. ALSO RQUIRES THE BOARDS MEMORY.
    //NOTE: ALSO DOESNT ACCOUNT FOR PIECES ON SAME TEAM. ALSO REQUIRES BOARDS MEMORY.

    return false;
}


char Pawn::get_specific_piece() {
    return 'P';
}