#ifndef GAME_H
#define GAME_H

#include <iostram>
#include <vector>
#include "Board.h"
using namespace std;

class Game {
private:
    Board board;

public:
    Game();

    void play();
};

#endif
