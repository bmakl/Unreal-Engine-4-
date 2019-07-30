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
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game in the global scope

//the entry point for our application
int main()
{
	do {
		PrintIntro();
		PlayGame();
		std::cout << std::endl;
	} while (AskToPlayAgain());												//It is entirely acceptable to write while(AskToPlayAgain()); as well - it might even look fancier
	
	
	return 0;		//exit application
}

//introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	//iterate over the number of guesses while the game is NOT won
	//and there is tries remaining
	while(!BCGame.IsGameWon() && (BCGame.GetCurrentTry() <= MaxTries)) //TODO change from FOR to WHILE loop once we can validate tries
	{
		FText Guess = GetValidGuess(); 


		//submit valid guess to the game, and receives counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		

		std::cout << "Bulls: " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows: " << BullCowCount.Cows << "\n\n";
	}

	//TODO add a game summary
}

//loop continually until we get a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please make sure your guess is an isogram (no repeating letters). \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please make sure all characters are lowercase and that there are no uppercase letters. \n";
			break;
		case EGuessStatus::Whitespace_Detected:
			std::cout << "Please make sure there are no spaces in your answer. \n";
			break;
		default:
			//assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping while the EGuessStatus is NOT ok

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