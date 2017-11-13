#pragma once

#include <vector>
#include "Tile.h"
#include "Console.h"

class Board
{
public:
	std::vector<std::vector<Tile>> Tiles;

private:
	Console m_Console;

public:
	Board ();
	Board (Console& console);
	void GenerateBoard ();
	std::vector<std::vector<int>> GetLevel (int levelNumber);
	void DrawBoard ();
	~Board ();

};

