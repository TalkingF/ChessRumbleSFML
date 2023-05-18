#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"
#include "Square.h"

class ChessBoard: public Game  {
    protected:
    Square ChessArray[8][8];
    sf::Texture boardTexture;
    sf::VertexArray boardVerticies
    
    
    public:
    //constructors + destructors
    ChessBoard();
    ~ChessBoard();

    //game pipeline
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow);
    void determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow);


    sf::Event getplayerInput(sf::Event gameEvent); //parse through determine events
    Square findSquare(sf::Event::mouseButton xPos, sf::Event::mouseButton yPos);

    //tilemap for visual pipeline. Drawing chess pieces last will cause them to render over squares.
    void makeBoard(/*Option-1*/ /*Option 2*/); //used on initialisaation of chessBoard.


    


    
};

#endif