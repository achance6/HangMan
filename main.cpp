#include <iostream>
#include <string>

char getGuess() {
	// TODO: handle bad inputs
	using std::cin;
	
	char guess{};
	cin >> guess;
	return guess;
}

char getCmd() {
	//TODO: handle bad inputs
	using std::cin;

	char cmd{};
	cin >> cmd;
	return cmd;
}

std::string handleGuess(char guess, 
	std::string_view answer, 
	std::string_view cur_display) {

	std::string display{ cur_display };
	bool guessCorrect{ false };
	for (std::size_t i{ 0 }; i < answer.length(); ++i) {
		if (display.at(i) == guess) break; // Already guessed this letter

		if (answer.at(i) == guess) {
			display.at(i) = guess;
			guessCorrect = true;
		}
	}
	return display; // move semantics?
}

constexpr std::string genAnswer() {
	//TODO: generate answer from dictionary
	return "hangman";
}

void play() {
	using std::string;
	using std::cout, std::cin;

	string answer{ genAnswer() };

	string display{};
	for (int i{ 0 }; i < answer.length(); ++i) display += '_';

	cout << "I'm thinking of a word with " << answer.length() << " letters.\n";
	cout << display << '\n';

	int lives{ 7 };
	while (lives > 0 && display.find('_') != string::npos) {
		cout << "Guess a letter (# to quit): ";
		char guess{ getGuess() };
		if (guess == '#') exit(0);

		string tmp{ display }; // to compare against new display
		display = handleGuess(guess, answer, display);
		bool guessCorrect{ static_cast<bool>(tmp.compare(display)) };

		if (!guessCorrect) {
			cout << "Incorrect.\n";
			lives--;
			cout << "You have " << lives << " lives remaining.\n";
		}

		// For different rules: one letter per guess

		/*std::size_t loc{ answer.find(guess) };

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
		}*/

		cout << display << '\n' << '\n';

	}
	cout << (lives > 0 ? 
		"You win!\n" : 
		"You lose! The answer was: " + answer + '\n');
}

int main() {
	using std::cout, std::cin;

	while (true) {
		cout << "Play Hangman? [Y/N]: ";
		char cmd{ getCmd() };

		if (cmd == 'Y' || cmd == 'y') play();
		else break;
	}
	
	return 0;
}