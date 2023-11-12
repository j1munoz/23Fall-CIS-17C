#include "Game.h"

Game::Game() {
    cout << "Welcome to BlackJack\n" << endl;
}

void Game::menu() {
    cout << "\t-------------------" << endl;
    cout << "\t    BlackJack Menu" << endl;
    cout << "\t1. Single Player" << endl;
    cout << "\t2. Multi Player" << endl;
    cout << "\t3. Rules" << endl;
    cout << "\t4. Quit" << endl;
    cout << "\t-------------------" << endl;
    cout << "Enter your choice here: ";
}

void Game::playGame(short numPlayers) {
    cout << "in game" << endl;
}

void Game::rules() {
    cout << "Hi and welcome to BlackJack!" << endl;
    cout << "Here are the rules to this version of BlackJack." << endl;
    cout << "1. You will be asked to enter the amount of players that will play"
         << ". The minimum amount is 1 and the max amount is 4 players." <<endl;
    cout << "2. Each player will be asked to enter their name." << endl;
    cout << "3. Each player is given two cards from the beginning." << endl;
    cout << "4a. An Ace is either a 1 or 11, depending on your choice." << endl;
    cout << "4b. If you happen to draw an Ace, you will be asked to assign it "
         << "to either 1 or 11." << endl;
    cout << "4c. If you enter an invalid number, you will be asked to try again"
         << "." << endl;
    cout << "5a. After getting your two cards, you will be asked to either draw"
         << " a new card, or stand (end your turn)." << endl;
    cout << "5b. If you want to draw, you will enter '1'." << endl;
    cout << "5c. If you want to stand, you will enter '2'." << endl;
    cout << "\nWINNING CONDITIONS (SINGLE PLAYER)" << endl;
    cout << "1. If you have total that is higher than the dealer and your total"
         << " is less than or equal to 21, you win the game." << endl;
    cout << "2. If you have a total that is less than or equal to 21 and the "
         << "dealer is bust (exceed 21), you win the game." << endl;
    cout << "3. If you go bust (exceed 21) and the dealer's total is less than "
         << "or equal to 21, the dealer wins the game." << endl;
    cout << "4. If you and the dealer have the exact same total that is less "
         << "or equal to 21, the dealer wins the game." << endl;
    cout << "5. If you go bust (exceed 21) and so does the dealer, the game "
         << "will end in a draw." << endl;
    cout << "\nWINNING CONDITIONS (MULTIPLAYER)" << endl;
    cout << "1. If one player has a higher total that is less than or equal to"
         << " 21 and that total is higher than the rest of the players, and if "
         << "that total is higher than the dealer, that player wins the game\n";
    cout << "2. If the dealer has a better total than everyone else, the dealer"
         << "wins. " << endl;
    cout << "3. If a set of players have the same total that is less than or "
         << "equal to 21, the game will end in a draw." << endl;
    cout << endl;
}

void Game::quit() {
    cout << "\n\t*****Thanks for Playing*****\n" << endl;
}