#include <string>
#include "Board.h"

using std::vector;

Board::Board ()
{
	m_Console = Console ();
	GenerateBoard ();
}

Board::Board (Console & console)
{
	m_Console = console;
	GenerateBoard ();
}

void Board::GenerateBoard ()
{
	vector<vector<int>> board = GetLevel (0);

	Tiles.resize (board.size ());

	for (int i = 0; i < board.size (); i++)
		Tiles[i].resize (board[i].size ());

	for (SHORT x = 0; x < board.size (); x++)
	{
		for (SHORT y = 0; y < board[x].size (); y++)
		{
			if (board[x][y] == 0)
				Tiles[x][y] = Tile (false, false, { x, y }, " ", 1);
			else if (board[x][y] == 1)
				Tiles[x][y] = Tile (false, true, { x, y }, std::string (1, (unsigned char)254), FOREGROUND_INTENSITY | 7);
			else if (board[x][y] == 2)
				Tiles[x][y] = Tile (false, false, { x, y }, " ", 1);
			else if (board[x][y] == 3)
				Tiles[x][y] = Tile (true, false, { x, y }, "#", FOREGROUND_INTENSITY | 3);
			else if (board[x][y] == 4)
				Tiles[x][y] = Tile (false, false, { x, y }, " ", FOREGROUND_INTENSITY | 5);
			else if (board[x][y] == 5)
				Tiles[x][y] = Tile (false, false, { x, y }, "+", FOREGROUND_INTENSITY | 6);
		}
	}
}

vector<vector<int>> Board::GetLevel (const int levelNumber)
{
	vector<vector<int>> level;

	switch (levelNumber)
	{
	case 0:
		level.resize (8);
		level[7] = { 1, 1, 1, 1, 0, 0, 0, 0 };
		level[6] = { 1, 2, 2, 1, 0, 0, 0, 0 };
		level[5] = { 1, 2, 2, 1, 1, 1, 1, 1 };
		level[4] = { 1, 2, 2, 2, 2, 2, 2, 1 };
		level[3] = { 1, 1, 4, 5, 1, 3, 2, 1 };
		level[2] = { 1, 2, 2, 2, 1, 2, 2, 1 };
		level[1] = { 1, 2, 2, 2, 1, 1, 1, 1 };
		level[0] = { 1, 1, 1, 1, 1, 1, 1, 1 };
		break;
	default:
		level.resize (8);
		level[7] = { 1, 1, 1, 1, 0, 0, 0, 0 };
		level[6] = { 1, 2, 2, 1, 0, 0, 0, 0 };
		level[5] = { 1, 2, 2, 1, 1, 1, 1, 1 };
		level[4] = { 1, 2, 2, 2, 2, 2, 2, 1 };
		level[3] = { 1, 1, 4, 5, 1, 3, 2, 1 };
		level[2] = { 1, 2, 2, 2, 1, 2, 2, 1 };
		level[1] = { 1, 2, 2, 2, 1, 1, 1, 1 };
		level[0] = { 1, 1, 1, 1, 1, 1, 1, 1 };
		break;
	}

	return level;
}

void Board::DrawBoard ()
{
	for (SHORT x = 0; x < Tiles.size (); x++)
	{
		for (SHORT y = 0; y < Tiles[x].size (); y++)
		{
			Tile t = Tiles[x][y];

			m_Console.Draw (t.Position, t.Symbol, t.Color);
		}
	}
}

Board::~Board ()
{
}
