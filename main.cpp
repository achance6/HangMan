#include <iostream>
#include <string>
#include <iostream>
#include "io.h"
#include "hangman.h"

int main() {
	using std::cout;
	// open + read dictionary at startup as it takes a couple seconds
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