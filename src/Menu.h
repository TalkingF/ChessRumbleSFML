
#ifndef MENU_H
#define MENU_H
//SFML inclusion

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <iostream>
#include <string>
#include "Game.h"

class Menu: public Game {
    protected:
    int numCategories = 5; //subject to change
    int categoryPos; //which category user is on
    sf::Font font; //font to be used for menu
    sf::Text category[5]; //text category, representing a menu item
    bool option1 = false;
    bool option2 = false;
    bool confirm = false;

    public:
    //constructors + destructors
    Menu();
    ~Menu(); 

    //functions
    void upMenu();
    void downMenu();
    void enterMenu();
    void highlightCategory(int previousPos);

    //getters + setters
    sf::Text getCatgeory(int categoryIndex);
    bool getOption1();
    bool getOption2();
    bool getConfirm();
    sf::Font getFont();

    //game overrides 
    void determineEvent(sf::Event gameEvent, sf::RenderWindow *SFMLWindow);
    void update(sf::RenderWindow* SFMLWindow);
    void render(sf::RenderWindow* SFMLWindow);
    
};
#endif