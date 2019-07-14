#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }				//normal getter/setter syntax
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FBullCowGame::FBullCowGame() { Reset(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString guess)
{
	return false;
}


