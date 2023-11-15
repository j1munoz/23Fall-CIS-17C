#ifndef DEALER_H
#define DEALER_H

//#include "Player.h"
#include "AIPlayer.h"
#include <list>
#include <stack>

class Dealer : public Player {
    private:
        list<Card> deck;
        stack<Card> discarded;
    public:
       Dealer();
       void assignToHand(Card card);
       int assignAce(Card card);
       Card deal(); 
       void shuffleDeck();
};

#endif /* DEALER_H */
