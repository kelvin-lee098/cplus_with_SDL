#include "hangman.h"

#include <iostream>
#include <cstring>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;


string getLowerCaseString (const string& s)
{
    string res = s;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
            res[i] = tolower(s[i]);
    return res;
    }
}

void clearScreen()
{
	const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++)  cout << endl;
	}

string chooseWord(const char* fileName)
{
    vector<string> wordList;
    ifstream file(fileName);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            wordList.push_back(word);
        }
        file.close();chrono::milliseconds(500);
    }
    if (wordList.size() > 0) {
        int randomIndex = rand() % wordList.size();
        return getLowerCaseString (wordList[randomIndex]);
    } else return "";
}

void renderGame(const string& GuessWord, const string& badguess)
{

	clearScreen();
	int falseCount = badguess.length();

		cout << "Secret word: " << GuessWord << endl;

	if (falseCount > 0) {
		cout << "You've made " << falseCount << " wrong ";
		cout << (falseCount == 1 ? "guess" : "guesses");
		cout << ": " << badguess << endl;
	}
}

char readAGuess()
{
	char guess;
	cout << "\nyour guess: ";
	cin >> guess;
	return guess;
}

bool check (const string& word, char c)
{
	return (word.find_first_of(c) != string::npos);
}

string update (string& GuessWord, const string& word, char guess)
{
	for(int i=0; i < word.length(); i++ ){
		if(guess == word[i]){
			GuessWord[i] = guess;
		}
	}
	return GuessWord;
}
