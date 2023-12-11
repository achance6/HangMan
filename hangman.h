#pragma once
#include <vector>

void play();

bool handleGuess(char guess,
	std::string_view answer,
	std::string& display);

std::string genAnswer();

std::vector<std::string> getWords();

std::ifstream openDict();
