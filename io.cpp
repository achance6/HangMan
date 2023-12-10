#include "io.h"
#include <iostream>

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