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
		
		std::size_t loc{ answer.find(guess) };

		// Handles case where duplicate letters exist in answer
		while (loc != string::npos && display.at(loc) != '_') {
			loc = answer.find(guess, loc + 1);
		}

		if (loc != string::npos) {
			display.replace(loc, 1, 1, guess);
		}
		else {
			cout << "Incorrect.\n";
			lives--;
			cout << "You have " << lives << " lives remaining.\n";
		}

		cout << display << '\n';
		
	}

	cout << (lives > 0 ? "You win!" : "You lose!");
	return 0;
}