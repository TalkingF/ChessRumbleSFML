#include "ChessBoard.h"

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

sf::Event ChessBoard::getplayerInput(sf::Event GameEvent) {
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
            findSquare(this->gameEvent.mouseButton.x, this->gameEvent.mouseButton.y);
        }
        break;
}
//search tilemap or window? for square that was clicked, returns the square.
Square ChessBoard::findSquare(sf::Event::mouseButton xPos, sf::Event::mouseButton yPos) {

}

void ChessBoard::makeBoard(/*Option-1*/ /*Option 2*/) {
    //attenpts to load chess square textures
    if (!this->boardTexture.loadFromFile(/*board tileset location*/)) {
        return 0;
    }
    //vertex array of quad type (square)
    boardVerticies.setPrimitiveType(sf::Quads);
    boardVerticies.resize(256 * 256 * 4) //square res is probably easier



            
        
}