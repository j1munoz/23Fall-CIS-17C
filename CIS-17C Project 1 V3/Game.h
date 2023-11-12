#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include "Dealer.h"
using namespace std;

class Game {
    Dealer *dealer;
    queue<Player> players;
    public:
        Game();
        void menu();
        void playGame(short numPlayers);
        void rules();
        void quit();
        void reset();
};

#endif /* GAME_H */
