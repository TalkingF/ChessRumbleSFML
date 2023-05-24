#include <iostream>
#include <vector>
#include "Game.h"
#include "Square.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Game.h"
#include "Board.h"
#include "Piece.h"
using namespace std;

Game::Game(){
}
void Game::play() {
    // Initialize the board
    board.initialize();

    // Print the initial board state
    cout << "Initial Board State:" << endl;
    board.print();

    // Game loop
    bool isWhiteTurn = true;
    while (true) {
        // Determine the player's turn
        int player_colour = isWhiteTurn ? 1 : 0;
        cout << "Player " << player_colour << "'s turn. Enter move (e.g., a2 a4): ";

        // Read the move input from the player
        string startSquare, endSquare;
        cin >> startSquare >> endSquare;

        // Convert the input to row and column indices
        int startRow = startSquare[1] - '1';
        int startCol = startSquare[0] - 'a';
        int endRow = endSquare[1] - '1';
        int endCol = endSquare[0] - 'a';

        // Get the start and end squares
        Square& startSquareObj = board.get_square(startRow, startCol);
        Square& endSquareObj = board.get_square(endRow, endCol);

        // Check if the start square is empty or contains a piece of the opposite color
        Piece* startPiece = startSquareObj.get_piece();
        if (startPiece == nullptr || startPiece->get_colour() != player_colour) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Check if the move is legal for the selected piece
        if (!startPiece->legal_move(endRow, endCol, board)) {
            cout << "Illegal move. Try again." << endl;
            continue;
        }

        // Move the piece to the destination square
        endSquareObj.set_piece(startPiece);
        startPiece->set_position(endRow, endCol);
        startSquareObj.clear();

        // Print the updated board state
        cout << "Next turn:" << endl;
        board.print();

        // Check for game over conditions or other rules
        // ...

        // Switch turns
        isWhiteTurn = !isWhiteTurn;
    }
}
