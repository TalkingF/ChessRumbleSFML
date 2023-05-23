#ifndef GAME_H
#define GAME_H

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <iostream>


class Game {
    protected:
    int windowWidth = 1024;
    int windowHeight = 1024;
    sf::Event gameEvent;
    std::string scene;
    
    public:
    //constructors and destructors
    Game();
    ~Game();
        
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow);
    
    void determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow); //polls for events and responds

    //getters + setters
   
    sf::Event getGameEvent();
    int getWindowHeight();
    int getWindowWidth();
    std::string getScene();
    void setWindowHeight(int windowHeight);
    void setWindowWidth(int windowWidth);
    void setScene(std::string scene);


    
};
#endif