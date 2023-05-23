#include <iostream>
#include <vector>
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
  
    
    if (!this->boardTexture.loadFromFile("/home/jacksonb/ChessRumbleSFML/ChessRumbleSFML/src/Assets/Images/chessBoard.png")) {
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
            getSquare((this->gameEvent.mouseButton.x) / 8, (this->gameEvent.mouseButton.y) / 8);
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

void ChessBoard::render(sf::RenderWindow* SFMLWindow) {
    SFMLWindow->clear(sf::Color::Blue);
    SFMLWindow->draw(this->boardSprite);
    SFMLWindow->display();
}

bool ChessBoard::loadPieces() {
    //attempts to load 
    if (!chessTileset.loadFromFile("/home/jacksonb/ChessRumbleSFML/ChessRumbleSFML/src/Assets/Images/pieceTileset.png")) {
        std::cout << "Chess piece tileset failed to load";
        return false;
    }


    //converts 2d vector to a 2d array
    Square** temp;
    temp = new Square*[8];
    for (int i= 0; (i < 8); i++) { 
        temp[i] = new Square[8];
        for (int j = 0; (j < 8); j++) {
          temp[i][j] = squares[i][j];
        }
    }      
    //sets vertex array to  quads and resizes for game window
    chessVertexArray.setPrimitiveType(sf::Quads);
    chessVertexArray.resize(256); //64 quads, 4 verticies per?
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (temp[i][j].getPiece() == nullptr) {
                continue;
            }

            sf::Vertex* quad = &chessVertexArray[(i + j * 8) * 4];

            quad[0].position = sf::Vector2f(i * 128, j * 128);
            quad[1].position = sf::Vector2f((i + 1) * 128, j * 128);
            quad[2].position = sf::Vector2f((i + 1) * 128, (j + 1) * 128);
            quad[3].position = sf::Vector2f(i * 128, (j + 1) * 128);

            //values to be used to define texture coordinates in tilemap.
            int xShift; 
            int yShift = 1;

            //shifts down to white pieces
            if (temp[i][j].getPiece()->getColour() == true) {
                yShift = 128;
            }

            //takes char value of piece and converts to  xshift
            switch (temp[i][j].getPiece()->get_specific_piece()) {
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

    return true;

}

void ChessBoard::initializeBoard(Menu menuScene) {
    menuScene.getOption1();
    menuScene.getOption2();
}

void ChessBoard::InitializePieces() {
    squares.resize(8);
    for (int i = 0; i < 8; i++) {
        squares.at(i).resize(8);
    }
    for (int i = 0; i < 8; i++) { 
        squares[1][i].setPiece(new Pawn(false, 1, i));  // Black Pawns
        squares[6][i].setPiece(new Pawn(true, 6, i));  // White Pawns
        }

        squares[0][3].setPiece(new Queen(false, 0, 3));  // Black Queen
        squares[7][3].setPiece(new Queen(true, 7, 3));  // White Queen

        squares[0][2].setPiece(new Bishop(false, 0, 2)); // White Squared Black Bishop
        squares[0][5].setPiece(new Bishop(false, 0, 5)); // Black Squared Black Bishop
        squares[7][2].setPiece(new Bishop(true, 7, 2)); // Black Squared White Bishop
        squares[7][5].setPiece(new Bishop(true, 7, 5)); // White Squared White Bishop

        squares[0][1].setPiece(new Knight(false, 0, 1)); // Black Squared Black Knight
        squares[0][6].setPiece(new Knight(false, 0, 6)); // White Squared Black Knight
        squares[7][1].setPiece(new Knight(true, 7, 1)); // White Squared White Knight
        squares[7][6].setPiece(new Knight(true, 7, 6)); // Black Squared White Knight

        squares[0][0].setPiece(new Rook(false, 0, 0)); // White Squared Black Rook
        squares[0][7].setPiece(new Rook(false, 0, 7)); // Black Squared Black Rook
        squares[7][0].setPiece(new Rook(true, 7, 0)); // Black Squared White Rook
        squares[7][7].setPiece(new Rook(true, 7, 7)); // White Squared White Rook

        squares[0][4].setPiece(new King(false, 0, 4));  // Black King
        squares[7][4].setPiece(new King(true, 7, 4));  // White King
 }

//used to find square that is clicked, pase mouse click events through event handling
Square& ChessBoard::getSquare(int xPos, int yPos) {
    if (xPos < 1024) {
        xPos = (xPos / 128); 
    }
    else {
        xPos = 8;
    }

    if (yPos < 1024) {
        yPos = (yPos / 128);
    }
    else {
        yPos = 8; 
    }
        return squares[xPos][yPos];
}

const std::vector<std::vector<Square>>& ChessBoard::get_board() const {
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

    




