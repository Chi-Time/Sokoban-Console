#pragma once

#include <string>
#include <windows.h>

class Console
{
public:
	WORD Attribute;
	DWORD CharsWritten;
	HANDLE OutputHandle;
	COORD CursorPosition;
	CONSOLE_SCREEN_BUFFER_INFO Info;

public:
	Console ();

	void ClearScreen ();
	void SetCursorPosition (COORD position);
	void Draw (std::string message);
	void Draw (std::string message, WORD Color);
	void Draw (COORD position, std::string message);
	void Draw (COORD position, std::string message, WORD Color);

	~Console ();
};
