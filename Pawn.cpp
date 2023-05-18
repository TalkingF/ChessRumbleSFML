#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool colour_, int row_, int col_) : Piece(colour_, row_, col_) {}

bool Pawn::legal_move(int new_row, int new_col) {
    int move_direction = (colour) ? -1 : 1;

    Board board;
    const vector<vector<Square>>& boardData = board.get_board();
    const Square& currentSquare = boardData[row][col];

    // Check if the target square is within the board bounds
    if (!Piece::legal_move(new_row, new_col)) {
        return false;
    }

    // Check if the target square is occupied by another piece
    if (boardData[new_row][new_col].getPiece() != nullptr) {
        return false;
    }

    // Check for capturing an opponent's piece diagonally
    if (new_col == col + 1 || new_col == col - 1) {
        if (new_row == row + move_direction) {
            if (boardData[new_row][new_col].getPiece() != nullptr) {
                // Valid capturing move
                return true;
            }
        }
        // TODO: Implement en passant check
    }

    // Check for moving one space forward
    if (new_col == col && new_row == row + move_direction) {
        return true;
    }

    // Check for moving two spaces forward from the starting position
    if (new_col == col && new_row == row + 2 * move_direction && row == (colour ? 6 : 1)) {
        return true;
    }

    return false;
}

char Pawn::get_specific_piece() {
    return 'P';
}
