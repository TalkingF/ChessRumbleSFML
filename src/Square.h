#ifndef SQUARES_H
#define SQUARES_H

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "ChessBoard.h"
#include "Piece.h"

class Square: public ChessBoard {
    protected:
    Piece square[2];

    public:
    //constructors + destructors
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow);
    void determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow);
    //functions
    bool isCaptured(Squares square);
    


    


};

#endif