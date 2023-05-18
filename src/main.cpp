//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"
#include "Menu.h"

/*
Controls game loop & sfml back-end. Is mainly responsible for updating & rendering
what is sent to it. 
*/

int main() {
    
    //On startup
    Game g;
    sf::RenderWindow* SFMLWindow = new sf::RenderWindow(sf::VideoMode(g.getWindowWidth(),g.getWindowHeight()), "Chess Rumble", sf::Style::Titlebar | sf::Style::Close);
    SFMLWindow->setFramerateLimit(60);
    Menu menuScene;
    //checks font
    if (!menuScene.getFont().loadFromFile("/home/jacksonb/ChessRumbleSFML/ChessRumbleSFML/src/Fonts/NotoSansMath-Regular.ttf")) {
        std::cout << "Font failed to load";
        return 0;  
    }
    while (SFMLWindow->isOpen()) {
        //conditional until confirmation
        menuScene.update(SFMLWindow);
        menuScene.render(SFMLWindow);
    }
    return 0;
}