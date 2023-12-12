#pragma once
#include <vector>
#include <unordered_set>

/**
 * Plays a game of hangman.
 *
 */
void play();

/**
 * Handles the given guess by comparing it to the given state of the answer
 * and modifying the given display reference. Needs a guessHistory in order
 * to not penalize guesses that have already been made. 
 *
 * @param answer Correct answer to compare guess to
 * @param display Current display of letters
 * @param guessHistory History of guesses user has made. Will add current guess
 * to the history
 * @return True if guess is correct, false otherwise
 */
bool handleGuess(std::string_view answer, 
	std::string& display,
	std::unordered_set<char>& guessHistory);

/**
 * .
 *
 * @return
 */
std::string genAnswer();

/**
 * .
 *
 * @return
 */
std::vector<std::string> getWords();

/**
 * .
 *
 * @return
 */
std::ifstream openDict();

/**
 * .
 *
 * @param attempts
 * @return
 */
std::string buildHangman(int attempts);
