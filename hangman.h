#pragma once
#include <vector>
#include <unordered_set>

void play();

bool handleGuess(std::string_view answer,
	std::string& display,
	std::unordered_set<char>& guessHistory);

std::string genAnswer();

std::vector<std::string> getWords();

std::ifstream openDict();

std::string buildHangman(int attempts);
