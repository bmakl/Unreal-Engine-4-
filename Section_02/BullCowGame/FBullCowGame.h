#pragma once
#include<string>

using FString = std::string;
using int32 = int;
//NEVER EVER USE NAMESPACE STD IN A .h FILE!!!

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	//TODO make a more rich return value
	bool CheckGuessValidity(FString guess); //TODO make a more rich return value
	//provide a method counting bulls and cows, and then incrementing try number



	//^^^Please try and ignore this and focus on the interface above^^^
private:
	int32 MyCurrentTry; //see constructor
	int32 MyMaxTries; //see constructor
};