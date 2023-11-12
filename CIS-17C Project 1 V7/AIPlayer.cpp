#include "AIPlayer.h"

int AIPlayer::assignAce(Card card) {
    if(11 + score <= 21) return 11;
    return 1;
}
