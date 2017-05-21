#pragma once

#include <iostream>
#include "FBullCowGame.h"
#include <map>

// unreal friendly syntax
#define TMap std::map
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthMaxTries{ {3,5}, {4,7}, {5,13}, {6,15}, {7,20} };
	return WordLengthMaxTries[MyHiddenWord.length()];
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet"; // this MUST be an isogram

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // check isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // check lowercase 
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // lenght wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assumes same length as guess

	// loop through hidden word
	for (int32 i = 0; i < WordLength; i++) 
	{
		// if hidden word letter is same as guess letter
		if (MyHiddenWord[i] == Guess[i]) 
		{ 
			BullCowCount.Bulls++; // increment bulls
		}
		else // if not the same
		{
			for (int32 j = 0; j < WordLength; j++) // loop through guess word
			{
				// check if the letter from guess is in hidden
				// and increment cows if it does
				if (MyHiddenWord[j] == Guess[i]) { BullCowCount.Cows++; }
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) // for all letters in word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
		
	}

	return true; // in cases where \0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) { return false; }
	}

	return true; // handle \0
}

