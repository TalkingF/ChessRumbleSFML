#include "Menu.h"

//SFML inclusion
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include<stdlib.h>


Menu::Menu() {
    std::cout << "[1] Play" << std::endl;
    std::cout << "[2] Learn more" << std::endl;
    std::cout << "[3] Explosive Pawns" << std::endl;
    std::cout << "[4] Read from file" << std::endl;
    std::cout << "[5] Exit" << std::endl;      
}

Menu::~Menu() {
    
} 

void Menu::determineInput(char input) {
    switch (input) {
    case '1':
    this->confirm = true;
        break;
    case '2':
        this->learnMore();
        break;
    case '3':
        this->option1 = true;
        break;
    case '4':
        this->option2 = true;
        break;
    case '5':
        exit(0);
        break;
    default:
    std::cout << "Please enter a valid integer.";
        break;
    }
}

void Menu::learnMore() {
    std::cout << "SFML implementation of chess with a couple of variations" << std::endl;
    std::cout << "and limitations. Lucas Owers, Jackson Bunting." << std::endl;
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