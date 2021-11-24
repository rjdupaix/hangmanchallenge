#include "hangman.h"

const unsigned int lives = 6;

int main(int argc, char** argv) {
    hangman hangManGame;
    hangManGame.play();
    return 0;
}