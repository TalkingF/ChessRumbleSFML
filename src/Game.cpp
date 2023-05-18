#include "Game.h"
#include "Menu.h"
//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

//constructors + destructors
Game::Game() {
   
}
Game::~Game() { 

}
    
//getters + setters 

sf::Event Game::getGameEvent() {
    return this->gameEvent;
}

std::string Game::getScene() {
    return this->scene;
}
void Game::setScene(std::string scene) {
    this->scene = scene;    
}

int Game::getWindowHeight() {
    return this->windowHeight;
}

int Game::getWindowWidth() {
    return this->windowWidth;
}

//event polling and determing events. Returns event type. 
void Game::determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow) {
    switch (gameEvent.type)
    {
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
            this->gameEvent.mouseButton.x;
        }
        break;
    default:
        break;
    }

}
//update handles and game logic or events that need to be checked.
void Game::update(sf::RenderWindow *SFMLWindow) {
//event polling
    while (SFMLWindow->pollEvent(this->gameEvent)) {
        determineEvent(this->gameEvent, SFMLWindow);
    }
    
}

/*render handles sfml drawing and is to be called after update is finished as it
as it references the changes to update on what to render.*/
void Game::render(sf::RenderWindow *SFMLWindow) {
    SFMLWindow->clear();
    SFMLWindow->display();
}


