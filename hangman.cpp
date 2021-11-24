#include "hangman.h"
 void hangman::play() {
    cout << endl <<  "Welcome to the wonderful game of hangman!" << endl;
    cout << "The game is simple, you have to guess all the letters in a word." << endl;
    cout << "Everytime you guess wrong you lose a life. You have 6 lives." << endl;
    cout << "When guessing a word, I will only accept lower-case letters." << endl;

    char guess;
    do {
        auto wordToGuess = selectWord();
        setWord(wordToGuess->first);

        cout << endl << "Your word is " << wordToGuess->second.size() << " letters long." << endl;
        printWord();

        while (badGuesses != 6) {
            cout << "What is your guess?" << endl;
            guess = getUserInput();
            if (checkPreviouslyGuessed(guess)) { continue; }
            checkWord(guess, wordToGuess->second);
            cout << "Bad Guesses: " << badGuesses << " Good Guesses: " << goodGuesses << endl;
            printWord();
            if (lettersFilled == wordToGuess->second.size()) {
                cout << "Congratulations, you did it!" << endl;
                break;
            }
            if (badGuesses == 6) {
                cout << "Shucks! You're all out of chances. Better luck next time!" << endl;
            }
        }
        response = checkPlayAgain();
    } while (response);
}

map<string, vector<char>>::iterator hangman::selectWord() {
    auto dictionaryIter = dictionary.begin();
    srand(time(nullptr));
    std::advance(dictionaryIter, rand() % dictionary.size());
    string wordToGuess = dictionaryIter->first;
    return dictionaryIter;
}

char hangman::getUserInput() {
    char guess;
    cin >> guess;
    if (!isalpha(guess) || !std::islower(guess)) {
        cout << "Guess a lower-case letter please." << endl;
        guess = getUserInput();
        return guess;
    }
    cin.ignore(1, '\n');
    return guess;
}

void hangman::setWord(const string& selectedWord) {
    word.clear();
    for (unsigned int i = 0; i < selectedWord.size(); ++i) {
        word.push_back('_');
    }
}

bool hangman::checkPreviouslyGuessed(const char& guess) {
    if (guesses.find(guess) != guesses.end()) {
        cout << "You've already guessed " << guess << ". Please try again." << endl;
        return true;
    }
    return false;
}

void hangman::printWord() {
    for (char i : word) {
        cout << i;
    }
    cout << endl;
}

void hangman::checkWord(const char& guess, const vector<char>& letters) {
    bool correct = false;

    for (unsigned int i = 0; i < letters.size(); ++i) {
        if (guess == letters.at(i)) {
            guesses[guess] = true;
            word.at(i) = guess;
            lettersFilled++;
            correct = true;
        }
    }
    if (correct) {
        goodGuesses++;
        cout << "Good work!" << endl;
    }
    else { badGuesses++;
        cout << "Try again!" << endl;
    }
}

bool hangman::checkPlayAgain() {
    cout << "Would you like to play again? (Type yes or no)" << endl;
    string userResponse;
    std::getline(cin, userResponse);
    if (userResponse == "yes") {
        badGuesses = 0;
        goodGuesses = 0;
        lettersFilled = 0;
        response = false;
        guesses.clear();
        return true;
    }
    else if (userResponse == "no") { return false; }
    else {
        cout << "Please respond with 'yes' or 'no'" << endl;
        return checkPlayAgain();
    }
}