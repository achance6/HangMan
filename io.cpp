/*****************************************************************//**
 * @file   io.cpp
 * @brief  Contains functions pertaining to user input/output and validation
 * 
 * @author Ayden Chance
 * @date   December 2023
 *********************************************************************/
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

		// # is quit command
		if (!std::isalpha(guess) && guess != '#') {
			cout << "Please enter an alphabetical character\n";
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