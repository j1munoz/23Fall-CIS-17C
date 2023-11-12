#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

class Game {
    public:
        Game();
        void menu();
        void playGame(short numPlayers);
        void rules();
        void quit();
};

#endif /* GAME_H */

