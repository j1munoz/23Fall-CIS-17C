#include "Game.h"
#include "Validator.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    // Declare Variables
    Game game;
    Validator check;
    char choice;
    
    // Show the game menu
    do {
        game.menu();
        choice = check.charInput();
        switch(choice) {
            case '1':
                game.playGame(1);
                game.finalScores();
                game.reset();
                break;
            case '2':
                short numPlayers;
                do {
                    cout << "Enter the amount of players here (2-4 max): ";
                    numPlayers = check.shortInput(2, 4);
                } while(numPlayers < 2 || numPlayers > 4);
                game.playGame(numPlayers);
                game.finalScores();
                game.reset();
                break;
            case '3':
                game.createAI();
                game.playAI();
                game.AIFinalScores();
                game.resetAI();
                break;
            case '4':
                game.betAI();
                break;
            case '5':
                game.rules();
                break;
            case '6':
                game.quit();
                break;
            default:
                if(choice != '6')
                    cout << "ERROR: Wrong input, please try again." << endl;
        }
    } while(choice != '6');
    
    return 0;
}
