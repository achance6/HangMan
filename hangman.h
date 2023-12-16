/*****************************************************************//**
 * @file   hangman.h
 * @brief  Contains functions pertaining to running the game of hangman
 * 
 * @author Ayden Chance
 * @date   December 2023
 *********************************************************************/
#pragma once

#include <vector>
#include <unordered_set>

/**
 * Plays a game of hangman.
 *
 */
void play();

/**
 * Handles the logic associated with the guessing part of hangman.
 *
 * @param display Where the guessed letter will go. Is modified.
 * @param answer What the correct answer is.
 * @return True if player won, false otherwise.
 */
bool handleGuesses(std::string& display, std::string_view answer);

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
bool checkGuess(char guess,
	std::string_view answer, 
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
 * Opens dictionary text file for reading.
 *
 * @return stream referring to dictionary text file
 */
std::ifstream openDict();

/**
 * Builds the actual hangman depiction.
 *
 * @param attempts How far to draw the hangman. 0 returns just the gallows.
 * 7 returns the whole depiction.
 * @return The hangman depiction.
 */
std::string buildHangman(int attempts);

/**
 * Loads a hardcoded list of words into the given vector in case loading a
 * dictionary fails.
 *
 * @param words Vector to load words into.
 */
void loadPredefinedWords(std::vector<std::string>& words);

/**
 * Loads every word in given dictionary into words vector.
 *
 * @param words Vector to load words into.
 * @param dict Dictionary to use.
 * @param lowerLim Lower limit on word length to include.
 */
void loadDictionaryWords(std::vector<std::string>& words,
	std::ifstream& dict, int lowerLim);




