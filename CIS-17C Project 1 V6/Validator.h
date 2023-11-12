#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
using namespace std;

class Validator {
    private:
        char temp;
    public:
        Validator() {temp = ' ';}
        char charInput();
        short shortInput(short min, short max);
        int intInput(int choice1, int choice2);
        string stringInput();
};

#endif /* VALIDATOR_H */
