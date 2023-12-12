#pragma once
#include <vector>
#include <unordered_set>

/**
 * Plays a game of hangman.
 *
 */
void play();

/**
 * 
 *
 * @param answer
 * @param display
 * @param guessHistory
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
