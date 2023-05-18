#include "Game.h"
#include "Board.h"

int main() {
    Board board;
    board.initialize();
    board.print();

    // Game loop
    bool isWhiteTurn = true;
    while (true) {
        // Determine the player's turn
        char playerColour = isWhiteTurn ? 'W' : 'B';
        cout << "Player " << playerColour << "'s turn. Enter move (e.g., a2 a4): ";

        // Read the move input from the player
        string startSquare, endSquare;
        cin >> startSquare >> endSquare;

        // Convert the input to row and column indices
        int startRow = startSquare[1] - '1';
        int startCol = startSquare[0] - 'a';
        int endRow = endSquare[1] - '1';
        int endCol = endSquare[0] - 'a';

        // Get the start and end squares
        Square& startSquareObj = board.getSquare(startRow, startCol);
        Square& endSquareObj = board.getSquare(endRow, endCol);

        // Check if the start square has a piece of the player's colour
        Piece* startPiece = startSquareObj.getPiece();
        if (startPiece == nullptr || startPiece->getColour() != playerColour) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Check if the move is legal for the selected piece
        if (!startPiece->legal_move(endRow, endCol)) {
            cout << "Illegal move. Try again." << endl;
            continue;
        }

        // Move the piece to the destination square
        endSquareObj.setPiece(startPiece);
        startSquareObj.clear();

        // Print the updated board state
        cout << "Next turn:" << endl;
        board.print();

        // Switch turns
        isWhiteTurn = !isWhiteTurn;
    }

    return 0;
}
