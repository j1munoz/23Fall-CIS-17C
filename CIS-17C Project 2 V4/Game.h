#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>
#include <deque>
#include "Dealer.h"
#include "Gambler.h"
using namespace std;

class Game {
    Dealer *dealer;
    queue<Player> players;
    deque<Gambler> *gamblers;
    AIPlayer *ai;
    map<string, list<string>> gameState;
    string currentState;
    public:
        Game();
        void menu();
        void initializeStates();
        void addState(string from, string to);
        bool isValidState(string from, string to);
        void handleState(string state);
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
        void merge(deque<Gambler>& arr, int left, int middle, int right);
        void mergeSort(deque<Gambler>& arr, int left, int right);
};

#endif /* GAME_H */
