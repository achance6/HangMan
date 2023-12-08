#include <iostream>
#include <string>

int main() {
	using std::string;
	using std::cout, std::cin;

	string answer{ "hangmann" };

	string display{};
	for (int i{ 0 }; i < answer.length(); ++i) display += '_';

	cout << "I'm thinking of a word with " << answer.length() << " letters.\n";
	cout << display << '\n';

	int lives{ 10 };
	while (lives > 0 && display.find('_') != string::npos) {
		cout << "Guess a letter (# to quit): ";
		char guess{};
		cin >> guess;
		if (guess == '#') exit(0);

		bool guessCorrect = false;
		for (std::size_t i{ 0 }; i < answer.length(); ++i) {
			if (display.at(i) == guess) break; // Already guessed this letter

			if (answer.at(i) == guess) {
				display.at(i) = guess;
				guessCorrect = true;
			}
		}


		if (!guessCorrect) {
			cout << "Incorrect.\n";
			lives--;
			cout << "You have " << lives << " lives remaining.\n";
		}

		cout << display << '\n';
		
	}

	cout << (lives > 0 ? "You win!" : "You lose!");
	return 0;
}