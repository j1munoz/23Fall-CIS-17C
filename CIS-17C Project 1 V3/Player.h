#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "Card.h"

class Player {
    protected:
        set<Card> hand;
        int score;
        string name;
    public:
        Player(){score = 0;};
        Player(string name);
        void addToHand(Card card);
        string getName() {return name;}
        void showCurrentScore();
        int assignAce(Card card);
        Player operator = (const Player &right);
};

#endif /* PLAYER_H */
