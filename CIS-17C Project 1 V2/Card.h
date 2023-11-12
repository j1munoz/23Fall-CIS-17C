#ifndef CARD_H
#define CARD_H

#include <map>
#include <string>
using namespace std;

class Card {
    private:
        map<string, int> cardVal;
    public:
        Card(string card, int value);
        string getCard() {return cardVal->first;}
        int getValue() {return cardVal->second;}
};

#endif /* CARD_H */

