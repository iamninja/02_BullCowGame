#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO
	bool CheckGuessValidity(std::string); // TODO
	
private:
	int MyCurrentTry;
	int MyMaxTries;
};
