#include<iostream>
#include<string>
using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
string ReturnGuess(string guess);

//the entry point for our application
int main()
{
	PrintIntro();
	
	PlayGame();
	
	cout << endl;
	
	
	return 0;		//exit application
}

//introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game" << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	//iterate over the number of guesses and use GetGuessPrintBack
	constexpr int NumberOfGuesses = 4;
	for (int i = 0; i <= NumberOfGuesses; i++)
	{
		string Guess = GetGuess();
		ReturnGuess(Guess);
		cout << endl;
	}
}


string GetGuess()
{
	//get a guess from the player
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);	
	return Guess;
}

string ReturnGuess(string guess)
{
	//repeat the guess back to them
	cout << "Your guess was: " << guess << endl;
	return guess;
}