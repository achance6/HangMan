#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <vector>
#include "io.h"
#include "hangman.h"

//#define DEBUG

void play() {
	using std::string;
	using std::cout, std::cin;

	string answer{ genAnswer() };

	string display{};
	// init display
	for (int i{ 0 }; i < answer.length(); ++i) display += '_';

	cout << "I'm thinking of a word with " << answer.length() << " letters.\n";
	cout << display << '\n';

	int lives{ 7 };
	while (lives > 0 && display.find('_') != string::npos) {
		cout << "Guess a letter (# to quit): ";
		bool guessCorrect{ handleGuess(getGuess(), answer, display) };

		if (!guessCorrect) {
			cout << "Incorrect.\n";
			lives--;
			cout << "You have " << lives << " lives remaining.\n";
		}

		cout << display << '\n' << '\n';

	}
	cout << (lives > 0 ?
		"You win!\n" :
		"You lose! The answer was: " + answer + '\n');
}

bool handleGuess(char guess,
	std::string_view answer,
	std::string& display) {

	if (guess == '#') exit(0); // TODO: really the best way?

	bool guessCorrect{ false };
	for (std::size_t i{ 0 }; i < answer.length(); ++i) {
		// Already guessed this letter, no lives deducted
		if (display.at(i) == guess) {
			guessCorrect = true;
			std::cout << "You already guessed this letter.\n";
			break;
		}
		if (answer.at(i) == guess) {
			display.at(i) = guess;
			guessCorrect = true;
		}
	}

	return guessCorrect; 
}

std::string genAnswer() {
	std::vector<std::string> words{ getWords() };

	// TODO: use actual random number
	auto rand = std::chrono::steady_clock::now().time_since_epoch().count()
		% words.size();

	return words.at(rand);
}

std::vector<std::string> getWords() {
	using std::string;

	// dictionary only read once.
	static std::vector<string> words{};

	if (words.empty()) {

#ifdef DEBUG
		auto startTime{ std::chrono::steady_clock::now() };
#endif

		auto dict{ openDict() };
		while (dict) {
			string word{};
			dict >> word;
			// Hangman answers at least 7 letters long
			if (word.length() >= 7) { words.push_back(word); };
		}
		dict.close();

#ifdef DEBUG
		auto endTime{ std::chrono::steady_clock::now() };
		double duration{ 
			std::chrono::duration_cast<
			std::chrono::duration<double, std::ratio<1>>>
			(endTime - startTime).count() 
		};
		std::cout << "Dictionary took " << duration << "ms to read.\n";
#endif

	}
	return words; //move semantics?
}

std::ifstream openDict() {
	//std::filesystem::path cwd = std::filesystem::current_path();
	//cout << "Current working directory is: " << cwd << '\n';

	std::ifstream dict{};
	dict.open("words_alpha.txt");
	if (!dict) {
		std::cout << "Failure opening dictionary";
		exit(1); //TODO: is this the best choice here?
	}
	return dict;
}
