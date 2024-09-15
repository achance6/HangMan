/*****************************************************************/ /**
 * @file   io.cpp
 * @brief  Contains functions pertaining to user input/output and validation
 *
 * @author Ayden Chance
 * @date   December 2023
 *********************************************************************/
#pragma once

/**
 * Clears out cin stream.
 *
 */
void ignoreLine();

/**
 * Get guess from user in form of a character.
 *
 * @return User's guess.
 */
char getGuess();

/**
 * Get command from user.
 *
 * @return User given command.
 */
char getCmd();
