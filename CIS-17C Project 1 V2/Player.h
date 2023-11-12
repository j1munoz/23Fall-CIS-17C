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
        Player(string name);
        string getName() {return name;}
        void assignAce();
};

#endif /* PLAYER_H */
