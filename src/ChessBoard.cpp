#include <iostream>
#include <vector>
#include <fstream>
#include "Square.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "ChessBoard.h"
#include "Game.h"
#include "Menu.h"
#include "BomberPawn.h"


//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


ChessBoard::ChessBoard() {

}
ChessBoard::~ChessBoard() {

}
void ChessBoard::loadBoard() {
  
    
    if (!this->boardTexture.loadFromFile("../src/Assets/Images/chessBoard.png")) {
        std::cout << "boardTexture failed to load";
    }
    this->boardSprite.setTexture(boardTexture);
}

void ChessBoard::determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow) {
    switch (gameEvent.type){
    case sf::Event::Closed: //close window through taskbar
        SFMLWindow->close();
        break;
    case sf::Event::KeyPressed: //close window through backspace
        if (this->gameEvent.key.code == sf::Keyboard::Backspace) {
            SFMLWindow->close();
        }

        break;
    case sf::Event::MouseButtonPressed: //left click event
        if (this->gameEvent.mouseButton.button == sf::Mouse::Button::Left) {
            if (this->startMousePos[0] == -1 && this->startMousePos[1] == -1 ) {
                this->startMousePos[0] = this->gameEvent.mouseButton.x / 128;
                this->startMousePos[1] = this->gameEvent.mouseButton.y / 128;       
                }
            else {
                this->endMousePos[0] = this->gameEvent.mouseButton.x / 128;
                this->endMousePos[1] = this->gameEvent.mouseButton.y / 128;     
            }  
        }       
        break;
    default:
        break;
    }
}


void ChessBoard::update(sf::RenderWindow* SFMLWindow) {
    while (SFMLWindow->pollEvent(this->gameEvent)) {
        this->determineEvent(this->gameEvent, SFMLWindow);
        
    }
       
    
}

void ChessBoard::render(sf::RenderWindow* SFMLWindow, ChessBoard board) {
    SFMLWindow->clear();
    SFMLWindow->draw(board.getBoardSprite());
    SFMLWindow->draw(board);
    SFMLWindow->display();
    

}

bool ChessBoard::loadPieces() {
    chessVertexArray.resize(0);


    //atboardMapts to load 
    if (!chessTileset.loadFromFile("../src/Assets/Images/pieceTileset.png")) {
        std::cout << "Chess piece tileset failed to load";
        return false;
    }


    //converts 2d vector to a 2d array
    
    Square** boardMap;
    boardMap = new Square*[SIZE];
    for (int i= 0; (i < SIZE); i++) { 
        boardMap[i] = new Square[SIZE];
        for (int j = 0; (j < SIZE); j++) {
          boardMap[i][j] = this->squares[i][j];
        }
    }      
    //sets vertex array to  quads and resizes for game window
    chessVertexArray.setPrimitiveType(sf::Quads);
    chessVertexArray.resize(256); //64 quads, 4 verticies per.
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (boardMap[i][j].get_piece() == nullptr) {
                continue;
            }

            sf::Vertex* quad = &chessVertexArray[(i + j * SIZE) * 4];

            quad[0].position = sf::Vector2f(i * 128, j * 128);
            quad[1].position = sf::Vector2f((i + 1) * 128, j * 128);
            quad[2].position = sf::Vector2f((i + 1) * 128, (j + 1) * 128);
            quad[3].position = sf::Vector2f(i * 128, (j + 1) * 128);

            //values to be used to define texture coordinates in tilemap.
            int xShift; 
            int yShift = 1;

            //shifts down to white pieces
            if (boardMap[i][j].get_piece()->get_Colour() == true) {
                yShift = 128;
            }

            //takes char value of piece and converts to  xshift
            switch (boardMap[i][j].get_piece()->get_specific_piece()) {
                case 66: //bishop
                xShift = 256;
                    break;
                case 75: //king
                xShift = 384;
                    break;
                case 78: //knight
                xShift = 128;
                    break;
                case 80: //pawn
                xShift = 640;
                    break;
                case 81: //queen
                xShift = 512;
                    break;
                case 82: //rook;
                xShift = 1;
                default:
                    break;
            }

            quad[0].texCoords = sf::Vector2f(xShift, yShift);
            quad[1].texCoords = sf::Vector2f(xShift + 128, yShift);
            quad[2].texCoords = sf::Vector2f(xShift + 128, yShift + 128);
            quad[3].texCoords = sf::Vector2f(xShift, yShift + 128);
        
        }
    }
   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            boardMap[i][j].clear();
        }
    }
    
    return true;

}

void ChessBoard::initializeBoard(Menu menuScene) {
    this->bomberPawns = menuScene.getOption1();
    this->loadState = menuScene.getOption2();
}

void ChessBoard::InitializePieces() {

    squares.resize(SIZE);
    for (int i = 0; i < SIZE; i++) {
        squares.at(i).resize(SIZE);
    }

    if (this->bomberPawns == true) {
        for (int i = 0; i < SIZE; i++) {
        squares[1][i].set_piece(new BomberPawn(false, 1, i));  // Black Pawns
        squares[6][i].set_piece(new BomberPawn(true, 6, i));  // White Pawns
        }
    }

    else {
    for (int i = 0; i < SIZE; i++) { 
        squares[1][i].set_piece(new Pawn(false, 1, i));  // Black Pawns
        squares[6][i].set_piece(new Pawn(true, 6, i));  // White Pawns
        }
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

//returns square based on row col
Square& ChessBoard::get_square(int xPos, int yPos) {
        return squares[xPos][yPos];
}

std::vector<std::vector<Square>>& ChessBoard::get_board() {
        return squares;
}
        
void ChessBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();
        

        // apply the tileset texture
        states.texture = &chessTileset;

        // draw the vertex array
        target.draw(this->chessVertexArray, states);
}

sf::Sprite ChessBoard::getBoardSprite() {
    return this->boardSprite;
}

int ChessBoard::getStartMousePos(int index) {
    return this->startMousePos[index];
}

int ChessBoard::getEndMousePos(int index) {
    return this->endMousePos[index];
}
void ChessBoard::resetMousePosSelection() {
    this->startMousePos[0] = -1;
    this->startMousePos[1] = -1;
    this->endMousePos[0] = -1;
    this->endMousePos[1] = -1;
}

   bool ChessBoard::isCheck(bool isWhiteTurn) {
    // Get the positions of the current player's king
    int currentPlayerKingRow = -1;
    int currentPlayerKingCol = -1;
    // Find the position of the current player's king
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            Piece* piece = squares[row][col].get_piece();
            if (piece != nullptr && piece->get_specific_piece() == 'K' && piece->get_Colour() == isWhiteTurn) {
                currentPlayerKingRow = row;
                currentPlayerKingCol = col;
                break; // Exit the loop once the king is found
            }
        }
        if (currentPlayerKingRow != -1 && currentPlayerKingCol != -1) {
            break; // Exit the outer loop as well
        }
    }
    
    // If the current player's king is not found, return false (not in check)
    if (currentPlayerKingRow == -1 || currentPlayerKingCol == -1) {
        return false;
    }
    // Check if any opponent's piece can capture the current player's king
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            Piece* piece = squares[row][col].get_piece();
            if (piece != nullptr && piece->get_Colour() != isWhiteTurn) {
                if (piece->legal_move(currentPlayerKingRow, currentPlayerKingCol, *this)) {
                    return true; // The current player's king is under attack (in check)
                }
            }
        }
    }
    return false; // The current player's king is not under attack (not in check)
}

