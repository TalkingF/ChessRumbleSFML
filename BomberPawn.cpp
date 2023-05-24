#include "BomberPawn.h"
#include "Board.h" // Include the Board header

BomberPawn::BomberPawn(bool colour, int row, int col) : Pawn(colour, row, col) {}

bool BomberPawn::legal_move(int new_row, int new_col, const Board& board) {
    // Check if the destination square is occupied by a piece of the same color
    if (board.get_square(new_row, new_col).get_piece() != nullptr &&
        board.get_square(new_row, new_col).get_piece()->get_colour() == colour) {
        return false;
    }

    // Determine the direction the pawn can move based on its color
    int direction = (colour) ? -1 : 1;

    // Check if the pawn is capturing an opponent's piece
    if (abs(new_col - col) == 1 && new_row == row + direction) {
        // Check if the destination square is occupied by an opponent's piece
        if (board.get_square(new_row, new_col).get_piece() != nullptr &&
            board.get_square(new_row, new_col).get_piece()->get_colour() != colour) {
            // Explode, destroying any piece in a three by three area
            explode(const_cast<Board&>(board), new_row, new_col); // Added const_cast to remove const so I can edit the board (THIS WAS THE PROBLEM)
            return true;  // Legal move after explosion
        }
        return false;  // Illegal move, capturing own piece
    }

    return Pawn::legal_move(new_row, new_col, board);
}

void BomberPawn::explode(Board& board, int center_row, int center_col) {
    // Define the bounds of the three by three area
    int start_row = std::max(center_row - 1, 0);
    int end_row = std::min(center_row + 1, Board::SIZE - 1);
    int start_col = std::max(center_col - 1, 0);
    int end_col = std::min(center_col + 1, Board::SIZE - 1);

    // Destroy any piece within the three by three area
    for (int row = start_row; row <= end_row; ++row) {
        for (int col = start_col; col <= end_col; ++col) {
            board.remove_piece(row, col);
        }
    }
}
