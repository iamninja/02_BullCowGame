#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(std::string); // TODO 

	// provide a method for counting bulls and cows and increase turn
	
private:
	int MyCurrentTry;
	int MyMaxTries;
};
