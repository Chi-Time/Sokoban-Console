#include "Player.h"



Player::Player ()
{
	m_Color = FOREGROUND_INTENSITY | 5;
	m_Position = { 0, 0 };
	m_Console = Console ();
	m_Symbol = std::string (1, (unsigned char)154);
}

Player::Player (Console & console)
{
	m_Color = FOREGROUND_INTENSITY | 5;
	m_Position = { 0, 0 };
	m_Console = console;
	m_Symbol = std::string (1, (unsigned char)154);
}

Player::Player (Console & console, WORD color)
{
	m_Color = color;
	m_Position = { 0, 0 };
	m_Console = console;
	m_Symbol = std::string (1, (unsigned char)154);
}

Player::Player (Console & console, COORD position, Board* board)
{
	m_Color = FOREGROUND_INTENSITY | 5;
	m_Position = position;
	m_Board = board;
	m_Console = console;
	m_Symbol = std::string (1, (unsigned char)154);
}

Player::Player (Console & console, COORD position, WORD color)
{
	m_Color = color;
	m_Position = position;
	m_Console = console;
	m_Symbol = std::string (1, (unsigned char)154);
}

void Player::Move (COORD direction)
{
	COORD nextPosition = { m_Position.X + direction.X, m_Position.Y + direction.Y };
	
	if (m_Board->Tiles[nextPosition.X][nextPosition.Y].IsBrick)
	{
		if (m_Board->Tiles[nextPosition.X + direction.X][nextPosition.Y + direction.Y].IsWall == false)
		{
			m_Board->Tiles[nextPosition.X][nextPosition.Y].IsBrick = false;
			m_Board->Tiles[nextPosition.X][nextPosition.Y].Symbol = " ";
			m_Board->Tiles[nextPosition.X + direction.X][nextPosition.Y + direction.Y].IsBrick = true;
			m_Board->Tiles[nextPosition.X + direction.X][nextPosition.Y + direction.Y].Symbol = "#";
			m_Board->Tiles[nextPosition.X + direction.X][nextPosition.Y + direction.Y].Color = FOREGROUND_INTENSITY | 3;

			m_Position = { nextPosition.X, nextPosition.Y };
		}
	}
	else if (m_Board->Tiles[nextPosition.X][nextPosition.Y].IsWall == false && m_Board->Tiles[nextPosition.X][nextPosition.Y].IsBrick == false)
		m_Position = { nextPosition.X, nextPosition.Y };
}

void Player::Draw ()
{
	m_Console.Draw (m_Position, m_Symbol, m_Color);
}

Player::~Player ()
{
}
