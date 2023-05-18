#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

class Board {
private:
    static const int SIZE = 8;
    vector<vector<Square>> squares;

public:
    Board() : squares(SIZE, vector<Square>(SIZE)) {}

    void initialize() {
        // Clears the board completely.
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                squares[i][j].clear();
            }
        }

        // Set up initial pieces
        // Set up the pawns.
        for (int i = 0; i < SIZE; ++i) {
            squares[1][i].setPiece('P');  // Black Pawns
            squares[6][i].setPiece('P');  // White Pawns
        }

        // Set up the Queens.
        squares[0][3].setPiece('Q');  // Black Queen
        squares[7][3].setPiece('Q');  // White Queen

        // Set up the Bishops.
        squares[0][2].setPiece('B'); // White Squared Black Bishop
        squares[0][5].setPiece('B'); // Black Squared Black Bishop
        squares[7][2].setPiece('B'); // Black Squared White Bishop
        squares[7][5].setPiece('B'); // White Squared White Bishop

        // Set up the Knights.
        squares[0][1].setPiece('N'); // Black Squared Black Knight
        squares[0][6].setPiece('N'); // White Squared Black Knight
        squares[7][1].setPiece('N'); // White Squared White Knight
        squares[7][6].setPiece('N'); // Black Squared White Knight

        // Set up the Rooks.
        squares[0][0].setPiece('R'); // White Squared Black Rook
        squares[0][7].setPiece('R'); // Black Squared Black Rook
        squares[7][0].setPiece('R'); // Black Squared White Rook
        squares[7][7].setPiece('R'); // White Squared White Rook

        // Set up the Queens.
        squares[0][4].setPiece('K');  // Black King
        squares[7][4].setPiece('K');  // White Queen

    }

    void print() const {
        std::cout << "   a b c d e f g h" << std::endl;
        for (int i = 0; i < SIZE; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < SIZE; ++j) {
                cout << squares[i][j].getPiece() << " ";
            }
            cout << endl;
        }
    }

    Square& getSquare(int row, int col) {
        return squares[row][col];
    }
};