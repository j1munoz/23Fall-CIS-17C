#include "Game.h"
#include <algorithm>

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
    // Create the dealer
    dealer = new Dealer();
    
    // Have the players assign their names
    cin.ignore();
    for(int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter the name for player " << i + 1 << ": ";
        getline(cin, name);
        players.push(Player(name));
    } 
    
    // Begin the game, start with the players
    dealer->shuffleDeck();
    for(int i = 0; i < numPlayers; i++) {
        char choice;
        Player current = players.front();
        
        cout << "\nAlright " << current.getName() << ", let's draw your ";
        cout << "first card." << endl;
        cout << "\nDrawing your first card...." << endl;
        current.addToHand(dealer->deal());
        cout << "\nDrawing your second card...." << endl;
        current.addToHand(dealer->deal());
        
        do {
            cout << "\nWould you like to draw another card? Enter 'Y' for yes";
            cout << " or enter 'N' for no: ";
            cin >> choice;
            while(toupper(choice) != 'Y' && toupper(choice) != 'N') {
                cout << "\nEnter 'Y' to draw another card, or enter 'N' to end";
                cout << " your turn: ";
                cin >> choice;
            }
            if(toupper(choice) == 'Y') {
                cout << "\nHere is your next card...." << endl;
                current.addToHand(dealer->deal());
                
                if(current.getScore() > 21) {
                    cout << "Sorry, " << current.getName() << ", you are bust.";
                    cout << "\nEnding turn....." << endl;
                    choice = 'N';
                }
            }
        }while(toupper(choice) != 'N');
        
        // Begin the next player's turn
        players.pop();
        players.push(current);
    }
    
    // Dealer's turn
    cout << "\n\nIt is now " << dealer->getName() << "'s turn, our dealer.\n";
    cout << "Drawing your first card...." << endl;
    dealer->addToHand(dealer->deal());
    cout << "Drawing your second card...." << endl << endl;
    dealer->addToHand(dealer->deal());
    
    do {
        if(dealer->getScore() <= 19) {
            cout << dealer->getName() << " decides to draw again." << endl;
            cout << "Here is your next card...." << endl;
            dealer->addToHand(dealer->deal());
            if(dealer->getScore() > 21)
                cout << dealer->getName() << " is bust." << endl;
        }
    }while(dealer->getScore() <= 19);
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

void Game::reset() {
    while(!players.empty()) players.pop();
    delete dealer;
}

void Game::finalScores() {
    int numPlayers = players.size();
    vector<Player> player(numPlayers);

    // Display all scores
    cout << "\n\nGame Over. Let's take a look at the scores." << endl;
    for(int i = 0; i < numPlayers; i++) {
        player[i] = players.front();
        players.pop();
        players.push(player[i]);
        cout << player[i].getName() << " had a score of " << player[i].getScore() << endl;
    }
    cout << dealer->getName() << " had a score of " << dealer->getScore() << endl;
    sort(player.begin(), player.end());
    
    // Determine who had the best score
    int winner = 0;
    if(numPlayers > 1) {
        for(int i = 1; i < numPlayers; i++) {
            if(player[i].getScore() > player[i - 1].getScore() && player[i].getScore() <= 21)
                winner = i;
        }
    }
    
    // Output the winner
    cout << "\nThe one with the best score was: " << player[winner].getName() << endl;
    if(player[winner].getScore() <= 21 && (dealer->getScore() > 21 || 
       player[winner].getScore() > dealer->getScore())) {
        cout << "The winner of the game is " << player[winner].getName() << endl;
    }
    else if(dealer->getScore() <= 21 && 
           (player[winner].getScore() > 21 || 
            player[winner].getScore() <= dealer->getScore())) {
        cout << "The winner of this game is " << dealer->getName() << endl;
    }
    else {
        cout << "The game has ended as a draw, nobody wins...." << endl;
    }
}
