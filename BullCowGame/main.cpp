#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Declarations
void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries();

	// Loop for the number of guesses
	for (int i = 0; i < MaxTries; i++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was, " << Guess << std::endl;
		std::cout << std::endl;
	}
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< "-letter isogram I'm thinking off?\n";
	std::cout << std::endl;

	return;
}

std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();
	// Get the guess
	std::cout << "Try " << CurrentTry << ". ";
	std::cout << "Enter your guess: ";
	std::string Guess = "";

	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
