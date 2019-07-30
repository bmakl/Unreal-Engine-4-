#include "FBullCowGame.h"
#include <iostream>

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }				//normal getter/setter syntax
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }


FBullCowGame::FBullCowGame() { Reset(); }

bool FBullCowGame::IsGameWon() const
{
	return bIsGameWon;
}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bIsGameWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	//if the guess isn't an isogram, return an error
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	//if the guess isn't all lowercase, return an error
	else if(false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	//if the guess has whitespace in it, return an error
	else if (false)
	{
		return EGuessStatus::Whitespace_Detected;
	}
	//if the guess is the wrong length, return an error
	else if (guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	//Otherwise return OK
	else
	{
		return EGuessStatus::OK;
	}
}

//receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	//loop through all letters in the hidden word
	int32 WordLength = (int32)MyHiddenWord.length();	//assuming the guess is the same length as Hidden Word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letters against guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if the letters match
			if (guess[GChar] == MyHiddenWord[MHWChar])
			{
				//and if they're in the same number location
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++; //increment bulls 
				}	
				else
				{
					BullCowCount.Cows++; //must be a cow
				}
			}

		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return BullCowCount;
}


