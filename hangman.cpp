/*****************************************************************/ /**
 * @file   hangman.cpp
 * @brief  Contains functions pertaining to running the game of hangman
 *
 * @author Ayden Chance
 * @date   December 2023
 *********************************************************************/
#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_set>
#include <cassert>
#include "io.h"
#include "hangman.h"
#include "random.h"

// Uncomment to have dictionary read time output.
//#define DEBUG

void play() {
    using std::string;
    using std::cout, std::cin;

    // Answer retrieved at random from a dictionary if available.
    // Otherwise a few hard-coded words are added and selected from.
    string answer{ genAnswer() };

    string display{};
    // init display
    for (int i{ 0 }; i < answer.length(); ++i) display += '_';

    cout << "I'm thinking of a word with " << answer.length() << " letters.\n";
    cout << buildHangman(0); // Just the gallows
    cout << display << '\n';

    cout <<
        (handleGuesses(display, answer) ? "You win!\n" : "You lose! The answer was: " + answer + '\n');
}

bool handleGuesses(std::string& display, std::string_view answer) {
    using std::cout;

    // Probably best to keep this hardcoded, buildHangman can't handle
    // a game with a different amount of lives.
    int lives{ 7 };

    // Used to not deduct lives on repeat guesses.
    std::unordered_set<char> guessHistory{};

    while (lives > 0 && display.find('_') != std::string::npos) {
        cout << "Guess a letter (# to give up, H to show guess history): ";
        char guess{ getGuess() };
        bool guessCorrect{};

        // quit command
        if (guess == '#') {
            lives = 0;
            break;
        }
        // display guess history command
        else if (guess == 'H') {
            for (char prevGuess : guessHistory) cout << prevGuess << ' ';
            cout << '\n';
            continue;
        }
        // process guess as normal
        else {
            guessCorrect = checkGuess(guess, answer, display, guessHistory);
        }

        if (!guessCorrect) lives--;

        cout << buildHangman(7 - lives);
        cout << display << '\n';
    }
    return lives > 0;
}

bool checkGuess(char guess,
                std::string_view answer,
                std::string& display,
                std::unordered_set<char>& guessHistory) {
    bool guessCorrect{ false };
    for (std::size_t i{ 0 }; i < answer.length(); ++i) {
        // Already guessed this letter, no lives deducted
        if (guessHistory.find(guess) != guessHistory.end()) {
            guessCorrect = true;
            std::cout << "You already guessed this letter. No lives deducted.\n";
            break;
        }
        if (answer.at(i) == guess) {
            display.at(i) = guess;
            guessCorrect = true;
        }
    }

    guessHistory.insert(guess);
    return guessCorrect;
}

std::string genAnswer() {
    std::vector<std::string> words{ getWords() };

    auto rand{
        static_cast<size_t>(
            Random::get(0, static_cast<int>(words.size()) - 1))
    };

    return words.at(rand);
}

std::vector<std::string> getWords(int lowerLim) {
    // static so dictionary only read from once.
    static std::vector<std::string> words{};

    if (words.empty()) {
#ifdef DEBUG
		auto startTime{ std::chrono::steady_clock::now() };
#endif
        auto dict{ openDict() };
        dict
            ? loadDictionaryWords(words, dict, lowerLim)
            : loadPredefinedWords(words);
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
    // Uncomment to see program's directory.
    //std::filesystem::path cwd = std::filesystem::current_path();
    //cout << "Current working directory is: " << cwd << '\n';

    std::ifstream dict{};
    dict.open("words_alpha.txt");

    if (!dict) std::cout << "Dictionary not found. Using pre-defined words.\n";

    return dict;
}

std::string buildHangman(int attempts) {
    assert(attempts >= 0);
    assert(attempts <= 7);

    std::string hangman{};

    // Could definitely be shorter, but this is easy to understand at a glance.
    switch (attempts) {
    case 0:
        hangman = "   ____   \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 1:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 2:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 3:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |   |   \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 4:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |  /|   \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 5:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |  /|\\ \n";
        hangman += "  |       \n";
        hangman += "  |       \n";
        break;
    case 6:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |  /|\\ \n";
        hangman += "  |  /    \n";
        hangman += "  |       \n";
        break;
    case 7:
        hangman = "   ____   \n";
        hangman += "  |   |   \n";
        hangman += "  |   O   \n";
        hangman += "  |  /|\\ \n";
        hangman += "  |  / \\ \n";
        hangman += "  |       \n";
        break;
    }
    return hangman; // move semantics?
}

void loadPredefinedWords(std::vector<std::string>& words) {
    words.push_back("dinosaur");
    words.push_back("alphabet");
    words.push_back("jazz"); // hardest hangman word
    words.push_back("dictionary");
    words.push_back("dungeon");
    words.push_back("monastery");
    words.push_back("commander");
    words.push_back("cryptography");
    words.push_back("stenography");
    words.push_back("epistomology");
}

void loadDictionaryWords(std::vector<std::string>& words,
                         std::ifstream& dict, int lowerLim) {
    // Dictionary assumed to be all lowercase, words separated by newlines.
    while (dict) {
        std::string word{};
        dict >> word;
        // default limit is 7
        if (word.length() >= lowerLim) {
            words.push_back(word);
        };
    }
}
