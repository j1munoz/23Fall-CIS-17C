#include "Game.h"

int main() {
    Game game;
    char choice;
    
    do {
        game.menu();
        cin >> choice;
        switch(choice) {
            case '1':
                game.playGame(1);
                game.reset();
                break;
            case '2':
                short numPlayers;
                do {
                    cout << "Enter the amount of players here (2-4 max): ";
                    cin >> numPlayers;
                } while(numPlayers < 2 || numPlayers > 4);
                game.playGame(numPlayers);
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
