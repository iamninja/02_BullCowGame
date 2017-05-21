/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic see FBullGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// Declarations
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game

// Entry point
int main()
{
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // cool bye
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of guesses
	// TODO change from FOR to WHILE
	for (int32 i = 0; i < MaxTries; i++) {
		FText Guess = GetGuess(); // TODO check valid guess

		// Submit valid guess to the game
		// Print number of bulls and cows

		std::cout << "Your guess was, " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO add a game summary
}

void PrintIntro()
{
	// Introduce the game
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< "-letter isogram I'm thinking off?\n";
	std::cout << std::endl;

	return;
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// Get the guess
	std::cout << "Try " << CurrentTry << ". ";
	std::cout << "Enter your guess: ";
	FText Guess = "";

	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
