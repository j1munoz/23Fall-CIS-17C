#include "Card.h"

Card::Card(string card, int cardNum) {
    if (card[1] == '0' || card[0] == 'J' || card[0] == 'Q' || card[0] == 'K')
        cardVal.insert(pair<string, int>(card, 10));
    else if(card[0] == 'A') cardVal.insert(pair<string, int>(card, 1));
    else cardVal.insert(pair<string, int>(card, static_cast<int>(card[0]) - 48));
    
    this->cardNum = cardNum;
}

string Card::getCard() {
    map<string, int>::iterator it;
    it = cardVal.begin();
    return it->first;
}

int Card::getValue() {
    map<string, int>::iterator it;
    it = cardVal.begin();
    return it->second;
}