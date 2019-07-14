/* This is the console executable, that makes use of the BullCow clas
This acts as the view in a MVC pattern, and is responsible for all user 
interaction. For game logic see the FBullCowGame Class
*/

#include<iostream>
#include<string>
#include"FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
FText ReturnGuess(FText guess);
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//the entry point for our application
int main()
{
	//bool bPlayAgain;
	do {
		PrintIntro();
		PlayGame();
		//bPlayAgain = AskToPlayAgain();
		std::cout << std::endl;
	} while (AskToPlayAgain());												//It is entirely acceptable to write while(AskToPlayAgain()); as well - it might even look fancier
	
	
	return 0;		//exit application
}

//introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//iterate over the number of guesses and use GetGuessPrintBack
	//TODO change from FOR to WHILE loop once we can validate tries
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess(); //TODO Make check for valid guesses

		//submit valid guess to the game
		//print number of Bulls and Cows

		ReturnGuess(Guess);
		std::cout << std::endl;
	}

	//TODO add a game summary
}


FText GetGuess()
{
	//get a guess from the player
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() <<  ". Enter your guess: ";
	std::getline(std::cin, Guess);	
	return Guess;
}

FText ReturnGuess(FText guess)
{
	//repeat the guess back to them
	std::cout << "Your guess was: " << guess << std::endl;
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	FText PlayAgain = "";
	std::getline(std::cin, PlayAgain);
	return (PlayAgain[0] == 'Y') || (PlayAgain[0] == 'y');
}