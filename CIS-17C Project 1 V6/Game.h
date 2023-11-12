#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include "Dealer.h"
using namespace std;

class Game {
    Dealer *dealer;
    queue<Player> players;
    AIPlayer *ai;
    public:
        Game();
        void menu();
        void playGame(short numPlayers);
        void createAI();
        void playAI();
        void betAI();
        void rules();
        void quit();
        void reset();
        void resetAI();
        void finalScores();
        void AIFinalScores();
};

#endif /* GAME_H */
