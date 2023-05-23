#include "Menu.h"

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

Menu::Menu() {
    this->categoryPos = 1;

    //CHESS RUMBLE->info about project
    category[0].setFont(font);
    category[0].sf::Text::setFillColor(sf::Color::White);
    category[0].setString("Chess Rumble");
    category[0].Bold;
    category[0].setCharacterSize(40); //default is 30???
    category[0].setPosition(sf::Vector2f(1024 / 2, 1024 / 6 * 1));

    //PLAY->loads menu with current settings
    category[1].setFont(font);
    category[1].sf::Text::setFillColor(sf::Color::White);
    category[1].setString("Play");
    category[1].setPosition(sf::Vector2f(1024 / 2, 1024 / 6 * 2));

    //OPTION_1->bool modifier
    category[2].setFont(font);
    category[2].sf::Text::setFillColor(sf::Color::White);
    category[2].setString("Option 1");
    category[2].setPosition(sf::Vector2f(1024 / 2, 1024 / 6 * 3));

    //OPTION_2->bool modifier
    category[3].setFont(font);
    category[3].sf::Text::setFillColor(sf::Color::White);
    category[3].setString("Option 2");
    category[3].setPosition(sf::Vector2f(1024 / 2, 1024 / 6 * 4));

    //Exit->closes game
    category[4].setFont(font);
    category[4].sf::Text::setFillColor(sf::Color::White);
    category[4].setString("Exit");
    category[4].setPosition(sf::Vector2f(1024 / 2, 1024 / 6 * 5));
}
Menu::~Menu() {

}

/* functions to be called from the event poller in Game.cpp. Will be called when up
or down is registered as an event. Changes categoryPos variable. */
void Menu::upMenu() {
    if (this->categoryPos >=2) {
        this->categoryPos--;
    }
    else {
        this->categoryPos = 5;
    }
}
void Menu::downMenu() {
    if (this->categoryPos <=4) {
        this->categoryPos++;
        
    }
    else {
        this->categoryPos = 1;
    }
}
//event poller will call if in this scene and [key.enter] is pressed
void Menu::enterMenu() {
    switch (this->categoryPos) {
        case 1: //CHESS RUMBLE
            break;
        case 2: //PLAY
        this->confirm = true;   
            break;
        case 3: //OPTION-1
        this->option1 = true;
            break;
        case 4: //Option-2
        this->option2 = true;
            break;
        case 5: //EXIT
            break;

        default:
            break;   
    }

}

void Menu::highlightCategory(int previousPos) {
    this->category[this->categoryPos - 1].sf::Text::setFillColor(sf::Color::Blue);
}

void Menu::loadMenu() {
       
    if (!this->getFont().loadFromFile("/home/jacksonb/ChessRumbleSFML/ChessRumbleSFML/src/Assets/Fonts/OpenSans-B9K8.ttf")) {
        std::cout << "Font failed to load";         
    }
}
 
//getters + setters    
sf::Text Menu::getCatgeory(int categoryIndex) {
    return this->category[categoryIndex];
}

bool Menu::getOption1() {
    return this->option1;    
}
bool Menu::getOption2() {
    return this->option2;
}
bool Menu::getConfirm() {
    return this->confirm;
}
sf::Font Menu::getFont() {
    return this->font;
}

//Event handling override for menu
void Menu::determineEvent(sf::Event gameEvent, sf::RenderWindow* SFMLWindow) {
    switch (this->gameEvent.type)
    {
    case sf::Event::KeyPressed:
        if (this->gameEvent.key.code == sf::Keyboard::Enter) {
            this->enterMenu();
        }
        else if(this->gameEvent.key.code == sf::Keyboard::Up) {
            this->upMenu();
        }
        else if(this->gameEvent.key.code = sf::Keyboard::Down) {
            this->downMenu();
        }
        else if (this->gameEvent.key.code == sf::Keyboard::Backspace) {
            SFMLWindow->close();
        }      
        break;
    case sf::Event::Closed: //close window through taskbar
        SFMLWindow->close();
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

void Menu::update(sf::RenderWindow *SFMLWindow) {
    while (SFMLWindow->pollEvent(this->gameEvent)) {
        this->determineEvent(this->gameEvent, SFMLWindow);
        
    }   
}

void Menu::render(sf::RenderWindow *SFMLWindow) {
    SFMLWindow->clear(sf::Color::Red);
    for (int i = 0; i < 5; i ++) {
        SFMLWindow->draw(this->category[i]);
    }
    SFMLWindow->display();
    
   
}
    