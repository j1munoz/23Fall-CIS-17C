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
        void showScore();
        int getScore() {return score;}
        void assignScore(int score) {this->score = score;}
        virtual int assignAce(Card card);
        Player operator = (const Player &right);
        bool operator < (const Player &right) const;
};

#endif /* PLAYER_H */
