#include "Dealer.h"
#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
using namespace std;

Dealer::Dealer() {
    this->name = "Jeff";
    string suits[4] = {" of Spades", " of Clubs", " of Diamonds", " of Hearts"};
    string faces[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", 
                        "Q", "K"};
    
    // Create the remaining deck
    leftover = new CardsRemain*[52];
    for(int i = 0; i < 52; i++) {
        leftover[i] = new CardsRemain;
        leftover[i]->card = "";
        leftover[i]->hashValue = -1;
        leftover[i]->next = nullptr;
    }
    
    // Create the deck
    int cards = 1;  // Keeps tracks of how many cards there are
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card card(faces[j] + suits[i], cards++);
            deck.emplace_back(card);
            int hashValue = SDBMHash(card.getCard());
            hashValue = abs(hashValue);
            if(leftover[hashValue % 52]->hashValue == -1) {
                leftover[hashValue % 52]->hashValue = hashValue;
                leftover[hashValue % 52]->card = card.getCard();
            }
            else insertNode(hashValue, card.getCard(), leftover[hashValue % 52]);
        }
    }
    
}

Card Dealer::deal() {
    Card temp = deck.front();
    int hash = SDBMHash(temp.getCard());
    deleteNode(leftover[abs(hash) % 52], temp.getCard());
    deck.pop_front();
    return temp;
//    discarded.push(deck.front());
//    deck.pop_front();
//    return discarded.top();
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

unsigned int Dealer::SDBMHash(const string& str) {
   unsigned int hash = 0;
   int size = str.length();
   
   for(size_t i = 0; i < size; i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}

Dealer::~Dealer() {
    for(int i = 0; i < 52; i++) {
        deleteRow(leftover[i]);
        leftover[i] = NULL;
        delete leftover[i];
    }
    delete [] leftover;
}

void Dealer::deleteRow(CardsRemain *&head) {
    CardsRemain *current = head;
    CardsRemain *nextNode;
    
    while(current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void Dealer::insertNode(int hashValue, string card, CardsRemain *&head) {
    CardsRemain *newNode = new CardsRemain;
    newNode->hashValue = hashValue;
    newNode->card = card;
    newNode->next = nullptr;
    
    if(head == nullptr) head = newNode;
    else {
        CardsRemain *current = head;
        while(current->next != nullptr) current = current->next;
        current->next = newNode;
    }
}

void Dealer::deleteNode(CardsRemain *&head, string card) {
    CardsRemain *current = head;
    CardsRemain *prev = nullptr;
    
    while(current != nullptr && current->card != card) {
        prev = current;
        current = current->next;
    }
    
    if(current != nullptr) {
        if(prev != nullptr) prev->next = current->next;
        else head = current->next;
    }
    delete current;
}

void Dealer::displayRemain() {
    cout << "\n\nHere were the remaining cards: " << endl;
    for(int i = 0; i < 52; i++) {
        CardsRemain *node = leftover[i];
    
        while(node != nullptr) {
            cout << node->card << endl;
            node = node->next;
        }
    }
}