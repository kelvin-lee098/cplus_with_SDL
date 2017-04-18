#ifndef HANGMAN_H
#define HANGMAN_H

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

const char dataFile[] = "hman.txt";
const int MAX_FALSE = 7;

string getLowerCaseString (const string& s);
void clearScreen();
string chooseWord(const char* fileName);

void renderGame(const string& GuessWord, const string& badguess);
char readAGuess();
bool check (const string& word, char c);
string update (string& GuessWord, const string& word, char guess);

#endif // HANGMAN_H
