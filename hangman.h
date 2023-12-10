#pragma once

void play();

std::string handleGuess(char guess,
	std::string_view answer,
	std::string_view cur_display);

constexpr std::string genAnswer();
