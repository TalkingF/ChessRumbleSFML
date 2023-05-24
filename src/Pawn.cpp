#include "Pawn.h"
#include "ChessBoard.h"
#include "Square.h"

Pawn::Pawn(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Pawn::legal_move(int new_row, int new_col, ChessBoard& board) {
    
    if (board.get_square(new_row, new_col).get_piece() != nullptr &&
        board.get_square(new_row, new_col).get_piece()->get_Colour() == colour) {
            return false;
    }
    // Determine the direction the pawn can move based on its color
    int direction = (colour) ? -1 : 1;

    
    // Check if the pawn is moving forward
    if (new_col == col && new_row == row + direction) {
        // Check if the destination square is unoccupied
        return (board.get_square(new_row, new_col).get_piece() == nullptr);
    }

    // Check if the pawn is moving forward by two squares from its starting position
    else if (new_col == col && new_row == row + 2 * direction) {
        // Check if the pawn is on its starting row
        if ((colour && row == 6) || (!colour && row == 1)) {
            // Check if the squares in between are unoccupied
            return (board.get_square(row + direction, new_col).get_piece() == nullptr &&
                    board.get_square(new_row, new_col).get_piece() == nullptr);
        }
    }

    // Check if the pawn is capturing an opponent's piece
    else if (abs(new_col - col) == 1 && new_row == row + direction) {
        // Check if the destination square is occupied by an opponent's piece
        return (board.get_square(new_row, new_col).get_piece() != nullptr &&
                board.get_square(new_row, new_col).get_piece()->get_Colour() != colour);

    }
}

char Pawn::get_specific_piece() {
    return 'P';
}