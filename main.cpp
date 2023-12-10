#include <iostream>
#include <string>
#include "io.h"
#include "hangman.h"

int main() {
	using std::cout;

	while (true) {
		cout << "Play Hangman? [Y/N]: ";
		char cmd{ getCmd() };

		if (cmd == 'Y' || cmd == 'y') play();
		else break;
	}
	
	return 0;
}