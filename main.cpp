/*****************************************************************//**
 * @file   main.cpp
 * @brief  Console game of hangman
 * 
 * @author Ayden Chance
 * @date   December 2023
 *********************************************************************/
#include <iostream>
#include <string>
#include <iostream>
#include "io.h"
#include "hangman.h"

int main() {
	using std::cout;
	// open + read dictionary at startup as it takes a couple seconds
	// getWords() contains a static vector of dictionary words.
	cout << "Initializing...\n";
	getWords(); 

	while (true) {
		cout << "Play Hangman? [Y/N]: ";
		char cmd{ getCmd() };

		if (cmd == 'Y') play();
		else if (cmd == 'N') break;
	}
	
	return 0;
}