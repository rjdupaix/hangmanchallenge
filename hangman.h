#ifndef HANGMAN_HANGMAN_H
#define HANGMAN_HANGMAN_H
#include <vector>
#include <map>
#include <iostream>
#include <ctime>

using std::vector;
using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class hangman {
private:
    map<string,vector<char>> dictionary;
    unsigned int badGuesses;
    unsigned int goodGuesses;
    unsigned int lettersFilled;
    map<char,bool> guesses;
    vector<char> word;
    bool response;

public:
    hangman() {
        dictionary["thanksgiving"] = { 't', 'h', 'a', 'n', 'k', 's', 'g', 'i', 'v', 'i', 'n', 'g' };
        dictionary["turkey"] = { 't', 'u', 'r', 'k', 'e', 'y' };
        dictionary["stuffing"] = { 's', 't', 'u', 'f', 'f', 'i', 'n', 'g' };
        dictionary["potatoes"] = { 'p', 'o', 't', 'a', 't', 'o', 'e', 's' };
        dictionary["gravy"] = { 'g', 'r', 'a', 'v', 'y' };
        dictionary["a"] = { 'a' };
        dictionary["plate"] = { 'p', 'l', 'a', 't', 'e' };
        dictionary["rolls"] = { 'r', 'o', 'l', 'l', 's' };
        dictionary["roll"] = { 'r', 'o', 'l', 'l' };
        dictionary["clock"] = { 'c', 'l', 'o', 'c', 'k' };
        badGuesses = 0;
        goodGuesses = 0;
        lettersFilled = 0;
        response = false;
    }
    ~hangman() = default;
    void play();
    map<string, vector<char>>::iterator selectWord();
    char getUserInput();
    void setWord(const string& selectedWord);
    bool checkPreviouslyGuessed(const char& guess);
    void printWord();
    void checkWord(const char& guess,const vector<char>& letters);
    bool checkPlayAgain();
};

#endif //HANGMAN_HANGMAN_H
