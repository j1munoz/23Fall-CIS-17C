#include "Validator.h"
#include <iostream>
#include <limits>
#include <future>
using namespace std;

char Validator::charInput() {
    char input;
    while(true) {
        if(cin >> input) break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: Invalid input, please try again." << endl;
        }
    }
    return input;
}

short Validator::shortInput(short min, short max) {
    short input;
    while(true) {
        if(cin >> input && input >= min && input <= max) break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nERROR: Invalid input, please try again: ";
        }
    }
    return input;
}

int Validator::intInput(int choice1, int choice2) {
    int input;
    while(true) {
        if(cin >> input && (input == choice1 || input == choice2)) break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: Invalid input, please try again." << endl;
             cout << "\nPlease enter 1 or 11 to assign the ace: ";
        }
    }
    return input;
}

string Validator::stringInput() {
    string input;
    while(true) {
        cin.ignore();
        getline(cin, input);
        if(!input.empty()) return input;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nERROR: Invalid input, please try again: ";
        }
    }
    return input;
}

float Validator::floatInput(float min, float max) {
    float input;
    while(true) {
        if(cin >> input && input >= min && input <= max) break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nERROR: Invalid input, please try again: ";
        }
    }
    return input;
}
