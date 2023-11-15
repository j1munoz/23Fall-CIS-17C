#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
    public:
        AIPlayer(){name = "Bill";}
        AIPlayer(string name) {this->name = name;}
        int assignAce(Card card);
};

#endif /* AIPLAYER_H */
