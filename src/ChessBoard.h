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
    static const int SIZE = 8;
    std::vector<std::vector<Square>> squares;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
    public:
    //constructors + destructors
    ChessBoard();
    ~ChessBoard();

    //game pipeline
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow);
    void determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow);

    //update
    void initializeBoard(Menu menuScene);
    void InitializePieces();

    //render
    void loadBoard();
    bool loadPieces();

    //functions
    Square& getSquare(int xPos, int yPos); //to be used by mouse
    const std::vector<std::vector<Square>>& get_board() const;
    
    //getters + setters
    sf::Sprite getBoardSprite();

    
};

#endif