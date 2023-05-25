#include "Game.h"
#include "Menu.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "Square.h"

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

//constructors + destructors
Game::Game() {
   
}
Game::~Game() { 

}
//getters + setters 

sf::Event Game::getGameEvent() {
    return this->gameEvent;
}

int Game::getWindowHeight() {
    return this->windowHeight;
}

int Game::getWindowWidth() {
    return this->windowWidth;
}

void Game::play() {
    
    
    Menu *menu = new Menu; //creates menu and displays menu scene
    
 
    while (menu->getConfirm() == false) {
        char input; 
        std::cin >> input;
        menu->determineInput(input);
    }

    sf::RenderWindow* SFMLWindow = new sf::RenderWindow(sf::VideoMode(this->windowWidth,this->windowHeight), "Chess Rumble", sf::Style::Titlebar | sf::Style::Close);
    SFMLWindow->setFramerateLimit(60); //sets framerate to desired constant
    
    // Initialize the board
    ChessBoard *board = new ChessBoard; //creates chess board
    
    board->initializeBoard(*menu); //parses any menu vars to chessboard

    delete menu; 
    board->loadBoard(); //loads board image

    board->InitializePieces(); //initialise piece locations on startup


    bool isWhiteTurn = true;
    //Chess Board loop,will continue until something tries to close the window
    while (!this->gameEvent.type == sf::Event::Closed) {
        if (!board->loadPieces()) { //checks to make sure tileset can load
        std::cout << "Initialising pieces failed";
        }
        board->update(SFMLWindow);
        board->render(SFMLWindow, *board);
            // Determine the player's turn
            bool playerColour = isWhiteTurn ? 1 : 0;

            if (board->getEndMousePos(0) != -1) {
                board->resetMousePosSelection();   
            }
    
            //converts mouse clicks to row/cols and expose
            while (board->getEndMousePos(0) == -1) {
                board->update(SFMLWindow);
                std::this_thread::sleep_for(std::chrono::milliseconds(200));   
            }
        
            
            
            Square& startSquareObj = board->get_square(board->getStartMousePos(0), board->getStartMousePos(1));
            Square& endSquareObj = board->get_square(board->getEndMousePos(0), board->getEndMousePos(1));

            // Check if the start square has a piece of the player's colour
            Piece* startPiece = startSquareObj.get_piece();
            Piece* endPiece = endSquareObj.get_piece();
            if (startPiece == nullptr || startPiece->get_Colour() != playerColour) {
                continue;
            }

            // Check if the move is legal for the selected piece
            if (!startPiece->legal_move(board->getEndMousePos(0), board->getEndMousePos(1), *board)) {
                continue;
            }

            //checks friendly fire
            if (endPiece == nullptr) {
            }
            else  {
                if (startPiece->get_Colour() == endPiece->get_Colour()) {
                    continue;
                }
            }
            //checks 
            if (board->isKingTaken()) {
                break;
                
           
            }
         
            



            // Move the piece to the destination square
            endSquareObj.set_piece(startPiece);
            startPiece->set_position(board->getEndMousePos(0), board->getEndMousePos(1));
            startSquareObj.clear();
            
            
            

            // Print the updated board state


            // Check for game over conditions or other rules
            // ... (need to include checkmate conditons at the very least. Not sure if this can be done in king class.)

            // Switch turns
            isWhiteTurn = !isWhiteTurn;
    }    
} 



    








