#include "Dealer.h"
#include <algorithm>
#include <vector>
#include <random>

Dealer::Dealer() {
    this->name = "Jeff";
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

int Dealer::assignAce(Card card) {
    if(11 + score <= 21) return 11;
    return 1;
}

void Dealer::shuffleDeck() {
    deque<Card> tempDeck(deck.begin(), deck.end());
    random_device rd;
    mt19937 g(rd());
    shuffle(tempDeck.begin(), tempDeck.end(), g);
    copy(tempDeck.begin(), tempDeck.end(), deck.begin());
}
