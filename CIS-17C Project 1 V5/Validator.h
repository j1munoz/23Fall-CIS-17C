#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator {
    private:
        char temp;
    public:
        Validator() {temp = ' ';}
        char charInput();
        short shortInput(short min, short max);
        int intInput(int choice1, int choice2);
};

#endif /* VALIDATOR_H */
