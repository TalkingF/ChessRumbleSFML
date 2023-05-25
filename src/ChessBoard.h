#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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

class ChessBoard: public Game, public sf::Drawable, public sf::Transformable  {
    protected:
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
    sf::VertexArray chessVertexArray;
    sf::Texture chessTileset;
    std::vector<std::vector<Square>> squares;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    int startMousePos[2] = {-1, -1};
    int endMousePos[2] = {-1, -1};
    bool bomberPawns;
    bool loadState;
    
    
    public:
    static const int SIZE = 8;
    //constructors + destructors
    ChessBoard();
    ~ChessBoard();

    //game pipeline
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow, ChessBoard board);
    void determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow);

    //update
    void initializeBoard(Menu menuScene);
    void InitializePieces();

    //render
    void loadBoard();
    bool loadPieces();

    //functions
    Square& get_square(int xPos, int yPos); //to be used by mouse
    std::vector<std::vector<Square>>& get_board();
    void remove_piece(int row, int col);
    bool isCheck(bool isWhiteTurn);
    bool isKingTaken() const;

    
    //getters + setters
    sf::Sprite getBoardSprite();
    int getStartMousePos(int index);
    int getEndMousePos(int index);
    void resetMousePosSelection();
    int get_size() const; // Public getter for SIZE
    

    
};

#endif