#include "Game.h"
#include "Validator.h"
#include <algorithm>
#include <valarray>
#include <iomanip>

Game::Game() {
    cout << "Welcome to BlackJack\n" << endl;
}

void Game::menu() {
    cout << "\t-------------------" << endl;
    cout << "\t    BlackJack Menu" << endl;
    cout << "\t1. Single Player" << endl;
    cout << "\t2. Multi Player" << endl;
    cout << "\t3. Simulate a game" << endl;
    cout << "\t4. Bet on AI" << endl;
    cout << "\t5. Rules" << endl;
    cout << "\t6. Quit" << endl;
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

void Game::createAI() {
    // Get the AI name, then create it
    Validator check;
    string aiName;
    cout << "\nBefore we begin, enter a name for the AI: ";
    cin.ignore();
    aiName = check.stringInput();
    
    ai = new AIPlayer(aiName);
}

void Game::playAI() {
    // Begin the game
    dealer = new Dealer();
    
    // AI's turn
    cout << "It is now " << ai->getName() << "'s turn, the AI.\n";
    cout << "Drawing your first card...." << endl;
    ai->addToHand(dealer->deal());
    cout << "Drawing your second card...." << endl;
    ai->addToHand(dealer->deal());
    
    do {
        if(ai->getScore() <= 19) {
            cout << ai->getName() << " decides to draw again." << endl;
            cout << "Here is your next card...." << endl;
            ai->addToHand(dealer->deal());
            if(ai->getScore() > 21)
                cout << ai->getName() << " is bust." << endl;
        }
    } while(ai->getScore() <= 19);
    cout << ai->getName() << " ends their turn.\n" << endl;
    
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
    cout << dealer->getName() << " ends their turn.\n" << endl;
}

void Game::createGamblers(short numPlayers) {
    string name;
    Validator check;
    gamblers = new deque<Gambler>;
    
    cin.ignore();
    for(int i = 0; i < numPlayers; i++) {
        cout << "Enter the name for player " << i + 1 << ": ";
        name = check.stringInput();
        gamblers->push_back(Gambler(name));
    }
}

void Game::gamblerBets() {
    char guess;
    float betAmount;
    int numPlayers = gamblers->size();
    Validator check;
    
    // Get all the bets from the players
    cout << "\n\t-------------------------------------------------------"<<endl;
    cout << "\tAlright everyone, you will now place your bets." << endl;
    cout << "\tEnter 'W' if you think the AI will win." << endl;
    cout << "\tEnter 'L' if you think the AI will lose." << endl;
    cout << "\tIf you win your bet, you will receive double." << endl;
    cout << "\tIf you lose your bet, you will lose that amount." << endl;
    cout << "\tIf the game ends in a draw, you will not lose your bet.\n";
    cout << "\t-------------------------------------------------------\n"<<endl;
    for(int i = 0; i < numPlayers; i++) {
        Gambler current = gamblers->front();
        
        if(current.getMoney() <= 0) {
            cout << "Sorry " << current.getName() << ", since you have no more";
            cout << " funds, you are out.\n" << endl;
        }
        else {
            short lines = current.getName().length();
            cout << "\t" << current.getName() << "'s turn" << endl;
            cout << '\t';
            for (int i = 0; i < (lines + 7); i++) cout << "-";
            cout << endl;
            
            do {
                cout << "\tEnter your guess here: ";
                guess = check.charInput();
                if (toupper(guess) != 'W' && toupper(guess) != 'L')
                    cout << "\tERROR: Invalid guess entered, please try again."
                         << endl;
                current.setChoice(toupper(guess));
            } while (toupper(guess) != 'W' && toupper(guess) != 'L');
            
            // Get their bet amount
            cout << "\tEnter your bet amount here: $";
            betAmount = check.floatInput(0, current.getMoney());
            while (betAmount > current.getMoney() || betAmount <= 0) {
                if (betAmount > current.getMoney())
                    cout << "\tERROR: Insufficient funds to bet with, please "
                         << " try again." << endl;
                else if (betAmount <= 0)
                    cout << "\tERROR: You must place a bet, please try again."
                         << endl;
                cout << "\tEnter your bet amount here: $";
                betAmount = check.floatInput(0, current.getMoney());
            }
            current.setBet(betAmount);
            cout << endl;
        }
        
        gamblers->pop_front();
        gamblers->push_back(current);
    }
}

void Game::gamblerResults() {
    int numPlayers = gamblers->size();
    // Simulate the game
    createAI();
    playAI();
    AIFinalScores();
    
    if(ai->getScore() <= 21 && (dealer->getScore() > 21 || 
       ai->getScore() > dealer->getScore())) {
        cout << "\nHere are the results of the bets." << endl;
        for(int i = 0; i < numPlayers; i++) {
            Gambler current = gamblers->front();
            
            if(current.getChoice() == 'W') {
                cout << current.getName() << " won." << endl;
                if (current.getMoney() > 0) current.winBet();
            }
            else {
                cout << current.getName() << " lost." << endl;
                if (current.getMoney() > 0) current.loseBet();
            }
            cout << "Here is " << current.getName() << "'s new amount: $"
                 << current.getMoney() << endl;
            
            gamblers->pop_front();
            gamblers->push_back(current);
        }
    }
    else if(dealer->getScore() <= 21 && (ai->getScore() > 21 || 
            ai->getScore() <= dealer->getScore())) {
        cout << "\nHere are the results of the bets." << endl;
        for(int i = 0; i < numPlayers; i++) {
            Gambler current = gamblers->front();
            
            if(current.getChoice() == 'L') {
                cout << current.getName() << " won." << endl;
                if (current.getMoney() > 0) current.winBet();
            }
            else {
                cout << current.getName() << " lost." << endl;
                if (current.getMoney() > 0) current.loseBet();
            }
            cout << "Here is " << current.getName() << "'s new amount: $"
                 << current.getMoney() << endl;
            
            gamblers->pop_front();
            gamblers->push_back(current);
        }
    }
    else {
        cout << "\nThe game has ended in a draw, all players will not lose "
             << "their bets." << endl;
        
        for(int i = 0; i < numPlayers; i++) {
            Gambler current = gamblers->front();
            cout << "Here is " << current.getName() << "'s new amount: $"
                 << current.getMoney() << endl;
            gamblers->pop_front();
            gamblers->push_back(current);
        }
    }
    
    resetAI();
    
}

bool Game::playAgain() {
    int numPlayers = gamblers->size();
    int zeros = 0;
    char again;
    Validator check;
    
    for(int i = 0; i < numPlayers; i++) {
        Gambler current = gamblers->front();
        
        if(current.getMoney() == 0) zeros++;
        gamblers->pop_front();
        gamblers->push_back(current);
    }
    
    if(zeros == numPlayers) {
        cout << "\n**All players have no more money, the game will now end**\n";
        return false;
    }
    else {
        cout << "\nWould you like to play another round?" << endl;
        do {
            cout << "Enter 'Y' for yes, enter 'N' for no: ";
            again = check.charInput();
            if (toupper(again) != 'Y' && toupper(again) != 'N')
                cout << "ERROR: Invalid choice entered, please try again.\n";
        } while(toupper(again) != 'Y' && toupper(again) != 'N');
        if (toupper(again) == 'Y') return true;
        else return false;
    }
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

void Game::resetAI() {
    delete ai;
    delete dealer;
}

void Game::resetGambler() {
    sort(gamblers->begin(), gamblers->end());
    cout << "\nHere are your final scores." << endl;
    cout << "---------------------------" << endl;
    cout << showpoint << fixed << setprecision(2);
    while(!gamblers->empty()) {
        Gambler current = gamblers->front();
        
        cout << "Final score for " << current.getName() << ": $" << current.getMoney() << endl;
        gamblers->pop_front();
    }
    cout << endl;
    delete gamblers;
}

void Game::finalScores() {
    int numPlayers = players.size();
    Player winner("Nobody");
    
    // Display the scores, and determine who had the best score
    cout << "\n\nGame Over. Let's take a look at the scores." << endl;
    for (int i = 0; i < numPlayers; i++) {
        Player current = players.front();
        cout << current.getName() << " had a score of " << current.getScore() << endl;
        if(current.getScore() <= 21 && current.getScore() > winner.getScore())
            winner = current;
        players.pop();
        players.push(current);
    }
    cout << dealer->getName() << " had a score of " << dealer->getScore() << endl;
    
    // Output the results
    cout << "\nThe one with the best score was: " << winner.getName() << endl;
    if(winner.getScore() <= 21 && (dealer->getScore() > 21 || 
       winner.getScore() > dealer->getScore())) {
        cout << "The winner of the game is " << winner.getName() << endl;
    }
    else if(dealer->getScore() <= 21 && 
           (winner.getScore() > 21 || 
            winner.getScore() <= dealer->getScore())) {
        cout << "The winner of this game is " << dealer->getName() << endl;
    }
    else {
        cout << "The game has ended in a draw, nobody wins....." << endl;
    }
}

void Game::AIFinalScores() {
    cout << "\n\n*****The game has ended, let's take a look at the scores*****" << endl;
    cout << ai->getName() << " had a score of " << ai->getScore() << endl;
    cout << dealer->getName() << " had a score of " << dealer->getScore() << endl;
    
    // Determine who won
    if(ai->getScore() <= 21 && (dealer->getScore() > 21 || 
       ai->getScore() > dealer->getScore())) {
        cout << "The winner of this game is " << ai->getName() << "." << endl;
    }
    else if(dealer->getScore() <= 21 && (ai->getScore() > 21 || 
            ai->getScore() <= dealer->getScore())) {
        cout << "The winner of this game is " << dealer->getName() << endl;
    }
    else {
        cout << "The game has ended in a draw, nobody wins....." << endl;
    }
}
