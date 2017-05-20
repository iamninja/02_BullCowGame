#include <iostream>
#include <string>

using namespace std;

// Declarations
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

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
	// Loop for the number of guesses
	constexpr int MAX_GUESSES = 5;
	for (int i = 0; i < MAX_GUESSES; i++) {
		string Guess = GetGuess();
		cout << "Your guess was, " << Guess << endl;
		cout << endl;
	}
}

void PrintIntro()
{
	// Introduce the game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH
		<< "-letter isogram I'm thinking off?\n";
	cout << endl;

	return;
}

string GetGuess() 
{
	// Get the guess
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
