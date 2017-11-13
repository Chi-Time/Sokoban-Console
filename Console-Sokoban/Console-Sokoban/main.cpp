#include <iostream>
#include <string>
#include <conio.h>
#include "Board.h"
#include "Player.h"
#include "Console.h"

//TODO: Add in ability to recognise if brick is in goal.
//TODO: Increment amount when brick is in goal.
//TODO: Make bricks seperate entities which can move themselves.
//TODO: Document codebase.

int main ()
{
	Console console = Console ();
	Board board = Board (console);
	Player player = Player (console, { 3, 2 }, &board);

	while (true)
	{
		board.DrawBoard ();
		player.Draw ();

		if (_kbhit ())
		{
			switch (_getch ())
			{
			case 'w':
				player.Move ({ 0, -1 });
				break;
			case 's':
				player.Move ({ 0, 1 });
				break;
			case 'a':
				player.Move ({ -1, 0 });
				break;
			case 'd':
				player.Move ({ 1, 0 });
				break;
			default:
				break;
			}
		}
		
		Sleep (100);
	}

	_getch ();

	return 0;
}