#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialize to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(FString); // TODO 
	FBullCowCount SubmitGuess(FString);
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
