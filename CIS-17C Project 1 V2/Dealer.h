#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include <list>

class Dealer : public Player {
    private:
        list<Card> deck;
    public:
       set<Card> deal(); 
};

#endif /* DEALER_H */

