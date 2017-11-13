#pragma once

#include <string>
#include <windows.h>
#include "Console.h"

class Player
{
private:
	WORD m_Color;
	COORD m_Position;
	Console m_Console;
	std::string m_Symbol;

public:
	Player ();
	Player (Console& console);
	Player (Console& console, WORD color);
	Player (Console& console, COORD position);
	Player (Console& console, COORD position, WORD color);
	void Move (COORD direction);
	void Draw ();
	~Player ();

};

