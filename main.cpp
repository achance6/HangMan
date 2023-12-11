#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "io.h"
#include "hangman.h"

int main() {
	using std::cout;

	//std::filesystem::path cwd = std::filesystem::current_path();
	//cout << "Current working directory is: " << cwd << '\n';
	std::ifstream dict;
	dict.open("words_alpha.txt");
	if (!dict.is_open()) {
		cout << "Failure opening dictionary";
		exit(1);
	}
	
	while (true) {
		cout << "Play Hangman? [Y/N]: ";
		char cmd{ getCmd() };

		if (cmd == 'Y') play();
		else if (cmd == 'N') break;
	}
	
	return 0;
}