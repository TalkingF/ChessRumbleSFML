//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "Piece.h"
#include "Square.h"

int main() {
    Game g;
    
    sf::RenderWindow* SFMLWindow = new sf::RenderWindow(sf::VideoMode(g.getWindowWidth(),g.getWindowHeight()), "Chess Rumble", sf::Style::Titlebar | sf::Style::Close);
    SFMLWindow->setFramerateLimit(60);

    //to play after menu


    ChessBoard board;
    board.loadBoard(); //shows board png
    //board.initializeBoard(/*Menu*/); //grabs menu options and change startup {not implemented}
    board.loadBoard(); //shows board png
    board.InitializePieces(); //initialise piece locations on startup
    if (!board.loadPieces()) {
        std::cout << "Initialising pieces failed";
        return 0;
    }
    for (int i = 0; i < 420; i++) {
    
    SFMLWindow->clear();
    SFMLWindow->draw(board.getBoardSprite());
    SFMLWindow->draw(board);
    SFMLWindow->display();
    
    

    }
   
 


/*
    std::string input;

    // Game loop
    bool isWhiteTurn = true;
    while (true) {
        // Determine the player's turn
        char playerColour = isWhiteTurn ? 'W' : 'B';
        std::cout << "Player " << playerColour << "'s turn. Enter move (e.g., a2 a4): ";

        // Read the move input from the player
        std::string startSquare, endSquare;
        std::cin >> startSquare >> endSquare;


        // Convert the input to row and column indices
        int startRow = startSquare[1] - '1';
        int startCol = startSquare[0] - 'a';
        int endRow = endSquare[1] - '1';
        int endCol = endSquare[0] - 'a';

        // Get the start and end squares
        Square& startSquareObj = board.getSquare(startRow, startCol);
        Square& endSquareObj = board.getSquare(endRow, endCol);

        // Check if the start square has a piece of the player's colour
        // Check if the start square has a piece of the player's color
        Piece* startPiece = startSquareObj.getPiece();
             if (startPiece == nullptr || (startPiece->getColour() == 'W' && playerColour != 'W') ||
                   (startPiece->getColour() == 'B' && playerColour != 'B')) {
                    std::cout << "Invalid move. Try again." << std::endl;
                    continue;
        }


        // Check if the move is legal for the selected piece
        if (!startPiece->legal_move(endRow, endCol)) {
            std::cout << "Illegal move. Try again." << std::endl;
            continue;
        }

        // Move the piece to the destination square
        endSquareObj.setPiece(startPiece);
        startSquareObj.clear();

        // Print the updated board state
        std::cout << "Next turn:" << std::endl;
        

        // Switch turns
        isWhiteTurn = !isWhiteTurn;
    }
    */

    return 0;
}