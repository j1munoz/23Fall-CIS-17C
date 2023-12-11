#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Card {
    private:
        map<string, int> cardVal;
        int cardNum;
    public:
        Card();
        Card(string card, int cardNum);
        string getCard();
        int getValue();
        void setCardNum(int num) {cardNum = num;}
        void setValue(string card, int value) {cardVal[card] = value;}
        bool operator < (const Card &right) const {return cardNum < right.cardNum;}
};

#endif /* CARD_H */
