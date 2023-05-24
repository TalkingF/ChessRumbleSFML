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
   
    
    public:
    //constructors and destructors
    Game();
    ~Game();
        
  
    //getters + setters
   
    sf::Event getGameEvent();
    int getWindowHeight();
    int getWindowWidth();
    void play();


  


    
};
#endif