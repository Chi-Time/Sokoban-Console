#include "Console.h"



Console::Console ()
{
	Attribute = FOREGROUND_INTENSITY | 7;
	CharsWritten = 0;

	OutputHandle = GetStdHandle (STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo (OutputHandle, &Info);

	CONSOLE_CURSOR_INFO cursorInfo = { 50, false };
	SetConsoleCursorInfo (OutputHandle, &cursorInfo);

	CursorPosition = { 0, 0 };
	SetConsoleCursorPosition (OutputHandle, CursorPosition);
}

void Console::ClearScreen ()
{
	// The position of the first cell of the window to clear from.
	const COORD firstCellPosition = { 0, 0 };
	// The size of the current console window instance.
	const DWORD consoleSize = Info.dwSize.X * Info.dwSize.Y;

	// Fill screen with empty spaces.
	if (!FillConsoleOutputCharacter (OutputHandle, (TCHAR)' ', consoleSize, firstCellPosition, &CharsWritten))
		return;

	// Reset the console windows attributes.
	if (!FillConsoleOutputAttribute (OutputHandle, Info.wAttributes, consoleSize, firstCellPosition, &CharsWritten))
		return;

	// Reset the cursor position of the console back to where it was before.
	SetConsoleCursorPosition (OutputHandle, CursorPosition);

	// Reset the number of characters written to the screen.
	CharsWritten = 0;
}

void Console::SetCursorPosition (COORD position)
{
	CursorPosition = position;
	SetConsoleCursorPosition (OutputHandle, CursorPosition);
}

void Console::Draw (std::string message)
{
	SetConsoleTextAttribute (OutputHandle, Attribute);
	WriteConsole (OutputHandle, message.c_str (), message.size (), &CharsWritten, nullptr);
}

void Console::Draw (std::string message, WORD Color)
{
	SetConsoleTextAttribute (OutputHandle, Color);
	WriteConsole (OutputHandle, message.c_str (), message.size (), &CharsWritten, nullptr);
	SetConsoleTextAttribute (OutputHandle, FOREGROUND_INTENSITY | 7);
}

void Console::Draw (COORD position, std::string message)
{
	SetCursorPosition (position);

	SetConsoleTextAttribute (OutputHandle, Attribute);
	WriteConsole (OutputHandle, message.c_str (), message.size (), &CharsWritten, nullptr);
}

void Console::Draw (COORD position, std::string message, WORD Color)
{
	SetCursorPosition (position);

	SetConsoleTextAttribute (OutputHandle, Color);
	WriteConsole (OutputHandle, message.c_str (), message.size (), &CharsWritten, nullptr);
	SetConsoleTextAttribute (OutputHandle, FOREGROUND_INTENSITY | 7);
}

Console::~Console ()
{
}
