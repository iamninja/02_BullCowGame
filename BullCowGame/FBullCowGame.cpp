#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn
	MyCurrentTry++;
	// setup return value
	FBullCowCount BullCowCount;
	// loop throu all letters in the guess
		//compare letters againt the hidden word

	return BullCowCount;
}

