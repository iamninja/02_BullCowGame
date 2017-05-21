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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	PrintGameSummary();
	return;
}

void PrintIntro()
{
	// Introduce the game
	int32 HiddentWordLength = BCGame.GetHiddenWordLength();
	std::cout << "\n\nWelcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << HiddentWordLength;
	std::cout << "-letter isogram I'm thinking off?\n";
	std::cout << std::endl;

	return;
}

// Loop until the user gives valid input
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;

	do {
		// Get the guess
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << "/" << BCGame.GetMaxTries() << ". ";
		std::cout << "Enter your guess: ";
		Guess = "";
		std::getline(std::cin, Guess);

		// Check guess
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word in lowercase.\n\n";
			break;
		default:
			break; // guess is right
		}
	} while (Status != EGuessStatus::OK); // Loop until get valid input
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word? (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Good job!! You won in " << BCGame.GetCurrentTry() - 1 << " try(-ies)!\n";
	}
	else
	{
		std::cout << "You lose.. Better luck next time!\n";
	}
}

