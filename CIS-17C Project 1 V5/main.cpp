#include "Game.h"
#include "Validator.h"

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
                game.rules();
                break;
            case '4':
                game.quit();
                break;
            default:
                if(choice != '4')
                    cout << "ERROR: Wrong input, please try again." << endl;
        }
    } while(choice != '4');
    
    return 0;
}
