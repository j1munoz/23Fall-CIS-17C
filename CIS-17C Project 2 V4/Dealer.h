#ifndef DEALER_H
#define DEALER_H

//#include "Player.h"
#include "AIPlayer.h"
#include <list>
#include <stack>
#include <string>
using namespace std;

struct CardsRemain {
    int hashValue;
    string card;
    CardsRemain *next;
};

class Dealer : public Player {
    private:
        list<Card> deck;
        CardsRemain **leftover;
    public:
       Dealer();
       ~Dealer();
       void assignToHand(Card card);
       int assignAce(Card card);
       Card deal(); 
       void shuffleDeck();
       void hashDeck();
       unsigned int SDBMHash(const string& str);
       void deleteRow(CardsRemain *&head);
       void insertNode(int hashValue, string card, CardsRemain *&head);
       void deleteNode(CardsRemain *&head, string card);
       void displayRemain();
};

#endif /* DEALER_H */
