#include <ncurses.h>
#include <string.h>
#include "menus.h"

int main()
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	char *options[] = {"New Game", "About", "Quit"};
	char *selection = "Main";

	do {
		if ( strcmp(selection, "Main") == 0 ) {
			selection = show_menu( "CleanupRL", options, 3);
		} else if ( strcmp(selection, "About") == 0 ) {
			selection = show_menu( "About", options, 3);
		} else if ( strcmp(selection, "New Game") == 0 ) {
			selection = "Main";
		}

	} while ( strcmp(selection, "Quit") != 0 );

	endwin();

	return 0;
}
