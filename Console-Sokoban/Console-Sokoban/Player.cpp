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

Player::Player (Console & console, COORD position)
{
	m_Color = FOREGROUND_INTENSITY | 5;
	m_Position = position;
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

	m_Position = { nextPosition.X, nextPosition.Y };

	Draw ();
}

void Player::Draw ()
{
	m_Console.Draw (m_Position, m_Symbol, m_Color);
}

Player::~Player ()
{
}
