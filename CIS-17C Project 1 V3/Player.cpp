#include "Player.h"

Player::Player(string name) {
    this->name = name;
    score = 0;
}

void Player::addToHand(Card card) {
    cout << "inside" << endl;
    if(hand.find(card) == hand.end()) {
        cout << "\nYou drew a: " << card.getCard() << endl;
        string aceCheck = card.getCard();
        if(aceCheck[0] == 'A') score += assignAce(card);
        else score += card.getValue();
        hand.insert(card);
        showCurrentScore();
    }
    else {
        cout << "Duplicate found, exiting game." << endl;
        exit(EXIT_FAILURE);
    }
}

int Player::assignAce(Card card) {
    int assign;
    cout << "\nSince you drew an " << card.getCard() << "pick the number you ";
    cout << "want it to represent (1 or 11): ";
    cin >> assign;
    while(assign != 1 && assign != 11) {
        cout << "\nPlease enter 1 or 11 to assign the ace: ";
        cin >> assign;
    }
    card.setValue(card.getCard(), assign);
    return assign;
}

void Player::showCurrentScore() {
    cout << "Your current score is: " << score << endl;
}

Player Player::operator = (const Player &right) {
    this->name = right.name;
    this->score = right.score;
    return *this;
}