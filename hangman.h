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
 * @param answer Correct answer to compare guess to.
 * @param display Current display of letters.
 * @param guessHistory History of guesses user has made. Will add current guess
 * to the history.
 * @return True if guess is correct, false otherwise.
 */
bool handleGuess(std::string_view answer, 
	std::string& display,
	std::unordered_set<char>& guessHistory);

/**
 * Generate a new hangman answer from the English dictionary.
 *
 * @return English word.
 */
std::string genAnswer();

/**
 * Loads words from dictionary txt file into program vector if it has not
 * already been done in the program. Otherwise just returns the vector.
 *
 * @param lowerLim Lower limit of word length to add to vector. Default 7.
 * @return Vector of dictionary words. Quite large.
 */
std::vector<std::string> getWords(int lowerLim = 7);

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
