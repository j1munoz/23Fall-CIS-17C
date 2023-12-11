#ifndef GAMBLER_H
#define GAMBLER_H

#include <string>
using namespace std;

class Gambler {
    private:
        string name;
        float money;
        float bet;
        char choice;
    public:
        Gambler() {name = "none"; money = 500;}
        Gambler(string name) {this->name = name; money = 500;}
        void setChoice(char choice) {this->choice = choice;}
        void setBet(float bet) {this->bet = bet;}
        void winBet() {money += bet;}
        void loseBet() {money -= bet;}
        string getName() {return name;}
        float getMoney() {return money;}
        char getChoice() {return choice;}
        bool operator < (const Gambler &right) const {return money < right.money;}
};

#endif /* GAMBLER_H */
