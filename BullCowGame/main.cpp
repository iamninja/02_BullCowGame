#include <iostream>
#include <string>

using namespace std;

// Declarations
void PrintIntro();
string GetGuessAndPrintBack();

// Entry point
int main()
{
	PrintIntro();

	// Loop for the number of guesses
	constexpr int MAX_GUESSES = 5;
	for (int i = 0; i < MAX_GUESSES; i++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}
	
	return 0;
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

string GetGuessAndPrintBack() 
{
	// Get the guess
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);

	// Print the guess back
	cout << "Your guess was, " << Guess << endl;

	return Guess;
}