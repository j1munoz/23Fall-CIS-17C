#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include <list>
#include <stack>

class Dealer : public Player {
    private:
        list<Card> deck;
        stack<Card> discarded;
    public:
       Dealer();
       Card deal(); 
       void shuffleDeck();
};

#endif /* DEALER_H */
