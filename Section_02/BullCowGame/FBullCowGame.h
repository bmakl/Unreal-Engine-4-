#pragma once
#include<string>

using FString = std::string;
using int32 = int;
//NEVER EVER USE NAMESPACE STD IN A .h FILE!!!

//all values initialized to zero
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Whitespace_Detected
};

enum class EResetStatus
{
	No_Hidden_Word,
	OK
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString guess) const; //TODO make a more rich return value
	bool IsGameWon() const;

	void Reset();	//TODO make a more rich return value
	

	//counts bulls and cows, increases try # assuming we have a valid guess
	FBullCowCount SubmitGuess(FString guess);
	



	//^^^Please try and ignore this and focus on the interface above^^^
private:
	int32 MyCurrentTry; //see constructor
	int32 MyMaxTries; //see constructor
	FString MyHiddenWord;
};