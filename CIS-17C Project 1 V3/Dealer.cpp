#include "Dealer.h"
#include <algorithm>
#include <vector>

Dealer::Dealer() {
    this->name = "bob";
    string suits[4] = {" of Spades", " of Clubs", " of Diamonds", " of Hearts"};
    string faces[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", 
                        "Q", "K"};
    
    // Create the deck
    int cards = 1;  // Keeps tracks of how many cards there are
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card card(faces[j] + suits[i], cards++);
            deck.emplace_back(card);
        }
    }
}

Card Dealer::deal() {
    discarded.push(deck.front());
    deck.pop_front();
    return discarded.top();
}

void Dealer::shuffleDeck() {
    vector<Card> tempDeck(deck.begin(), deck.end());
    random_shuffle(tempDeck.begin(), tempDeck.end());
    copy(tempDeck.begin(), tempDeck.end(), deck.begin());
}