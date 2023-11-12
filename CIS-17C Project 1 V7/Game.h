#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include "Dealer.h"
#include "Gambler.h"
using namespace std;

class Game {
    Dealer *dealer;
    queue<Player> players;
    queue<Gambler> *gamblers;
    AIPlayer *ai;
    public:
        Game();
        void menu();
        void playGame(short numPlayers);
        void createAI();
        void playAI();
        void createGamblers(short numPlayers);
        void gamblerBets();
        void gamblerResults();
        bool playAgain();
        void rules();
        void quit();
        void reset();
        void resetAI();
        void resetGambler();
        void finalScores();
        void AIFinalScores();
};

#endif /* GAME_H */
