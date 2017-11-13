#pragma once

#include <string>
#include <windows.h>

class Tile
{
public:
	WORD Color;
	bool IsWall;
	bool IsBrick;
	COORD Position;	
	std::string Symbol;

public:
	Tile ();
	Tile (bool isBrick, bool isWall, COORD position, std::string symbol, WORD color);
	~Tile ();
};

