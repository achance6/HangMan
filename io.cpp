#include <iostream>
#include <locale>
#include <limits>
#include <cctype>
#include "io.h"

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char getGuess() {
	using std::cin, std::cout;

	while (true) {
		char guess{};
		cin >> guess;

		// in case cin fails
		if (!std::cin) {
			cin.clear();
			ignoreLine();
		}
		ignoreLine();

		if (!std::isalpha(guess)) {
			cout << "Please enter an alphabetical character";
		}
		guess = std::tolower(guess, std::locale());

		return guess;
	}
}

char getCmd() {
	using std::cin, std::cout;

	while (true) {
		char cmd{};
		cin >> cmd;

		// in case cin fails
		if (!std::cin) {
			cin.clear();
			ignoreLine();
		}
		ignoreLine();
		cmd = std::toupper(cmd, std::locale());

		switch (cmd) {
		case 'Y':
		case 'N':
			return cmd;
		default:
			cout << "Invalid command. Please try again.\n";
		}

	}
}