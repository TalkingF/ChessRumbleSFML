#include <iostream>
#include <vector>
#include "Square.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Board.h"
#include "BomberPawn.h"

using namespace std;

Board::Board() : squares(SIZE, vector<Square>(SIZE)) {}

    static const int SIZE = 8;
    vector<vector<Square>> squares;

    void Board::initialize() {
        // Clears the board completely.
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                squares[i][j].clear();
            }
        }


        // Set up initial pieces
        for (int i = 0; i<8; i++){
        squares[1][i].set_piece(new BomberPawn(false, 1, i));  // Black Pawns
        squares[6][i].set_piece(new BomberPawn(true, 6, i));  // White Pawns
        }

        squares[0][3].set_piece(new Queen(false, 0, 3));  // Black Queen
        squares[7][3].set_piece(new Queen(true, 7, 3));  // White Queen

        squares[0][2].set_piece(new Bishop(false, 0, 2)); // White Squared Black Bishop
        squares[0][5].set_piece(new Bishop(false, 0, 5)); // Black Squared Black Bishop
        squares[7][2].set_piece(new Bishop(true, 7, 2)); // Black Squared White Bishop
        squares[7][5].set_piece(new Bishop(true, 7, 5)); // White Squared White Bishop

        squares[0][1].set_piece(new Knight(false, 0, 1)); // Black Squared Black Knight
        squares[0][6].set_piece(new Knight(false, 0, 6)); // White Squared Black Knight
        squares[7][1].set_piece(new Knight(true, 7, 1)); // White Squared White Knight
        squares[7][6].set_piece(new Knight(true, 7, 6)); // Black Squared White Knight

        squares[0][0].set_piece(new Rook(false, 0, 0)); // White Squared Black Rook
        squares[0][7].set_piece(new Rook(false, 0, 7)); // Black Squared Black Rook
        squares[7][0].set_piece(new Rook(true, 7, 0)); // Black Squared White Rook
        squares[7][7].set_piece(new Rook(true, 7, 7)); // White Squared White Rook

        squares[0][4].set_piece(new King(false, 0, 4));  // Black King
        squares[7][4].set_piece(new King(true, 7, 4));  // White King
        }
void Board::print() const {
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            Piece* piece = squares[i][j].get_piece();
            if (piece == nullptr) {
                cout << "0 ";
            } else {
                cout << piece->get_specific_piece() << " ";
            }
        }
        cout << endl;
    }
}

    Square& Board::get_square(int row, int col) {
        return squares[row][col];

    }

    const vector<vector<Square>>& Board::get_board() const {
    return squares;
}

const Square& Board::get_square(int row, int col) const {
    return squares[row][col];
}

void Board::remove_piece(int row, int col) {
    squares[row][col].clear();
}

