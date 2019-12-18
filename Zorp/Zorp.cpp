// Zorp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

const char* ESC = "\x1b";
const char* CSI = "\x1b[";

const char* TITLE = "\x1b[5;20H";
const char* INDENT = "\x1b[5C";
const char* YELLOW = "\x1b[93m";
const char* MAGENTA = "\x1b[95m";
const char* RESET_COLOR = "\x1b[0m";
const char* SAVE_CURSOR_POS = "\x1b[s";
const char* RESTORE_CURSOR_POS = "\x1b[u";

int main()
{
	DWORD dwMode = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	int height = 0;
	char firstLetterOfName = 0;
	int avatarHP = 0;

	std::cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << INDENT << "It is definately not related to any other text-based adventure game." << std::endl;

	std::cout << INDENT << "First, some questions..." << std::endl;

	std::cout << SAVE_CURSOR_POS;
	std::cout << INDENT << "How tall are you in centimeters?" << INDENT << YELLOW;

	std::cin >> height;
	std::cout << RESET_COLOR << std::endl;

	if (std::cin.fail())
	{
		std::cout << INDENT << "You have failed the first challenge and are eaten by a grue." << std::endl;
	}
	else
	{
		std::cout << INDENT << "You entered " << height << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	std::cout << INDENT << "What is the first letter of your name?" << INDENT << YELLOW;

	std::cin >> firstLetterOfName;
	std::cout << RESET_COLOR << std::endl;

	if (std::cin.fail() || !isalpha(firstLetterOfName))
	{
		std::cout << INDENT << "You have failed the second challenge and are eaten by a grue." << std::endl;
	}
	else
	{
		std::cout << INDENT << "You entered " << firstLetterOfName << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	std::cout << RESTORE_CURSOR_POS;
	std::cout << CSI << "A";
	std::cout << CSI << "4M";

	if (firstLetterOfName != 0)
	{
		avatarHP = (float)height / (firstLetterOfName * 0.02f);
	}
	else
	{
		avatarHP = 0;
	}

	std::cout << std::endl << INDENT << "Using a complex deterministic algorithm, it has been calculated you have " << avatarHP << " hit point(s)." << std::endl;

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();
	return 0;
}

