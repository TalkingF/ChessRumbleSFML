
#ifndef MENU_H
#define MENU_H
//SFML inclusion

#include <iostream>
#include <string>



class Menu {
    protected:
    

    

    bool option1 = false;
    bool option2 = false;
    bool confirm = false;
    

    public:
    //constructors + destructors
    Menu();
    ~Menu(); 

    //functions 
    void determineInput(char input);
    void learnMore();

    //getters + setters
    bool getOption1();
    bool getOption2();
    bool getConfirm();

    
};
#endif