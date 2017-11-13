#include "Tile.h"



Tile::Tile ()
{
	Color = 1;
	IsBrick = false;
	IsWall = false;
	Position = { 0, 0 };
	Symbol = " ";
}

Tile::Tile (bool isBrick, bool isWall, COORD position, std::string symbol, WORD color)
{
	Color = color;
	IsBrick = isBrick;
	IsWall = isWall;
	Position = position;
	Symbol = symbol;
}

Tile::~Tile ()
{
}
