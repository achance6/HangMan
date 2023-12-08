#include <iostream>
#include <string>

int main() {
	using std::string;
	using std::cout, std::cin;

	string answer{ "Hangman" };

	cout << "Guess a letter: ";
	char guess{};
	cin >> guess;

	string display{};
	for (int i{ 0 }; i < answer.length(); ++i) {
		display += '_';
	}
	return 0;
}