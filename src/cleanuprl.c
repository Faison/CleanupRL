#include <ncurses.h>
#include <string.h>
#include "menus.h"
#include "dialog.h"

int main()
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	char *options[] = {"New Game", "About", "Quit"};
	char *selection = "Main";

	char *about_lines[] = {"Some text about things",
				"And other stuff when I care about",
				"other stuff."};

	do {
		if ( strcmp(selection, "Main") == 0 ) {
			selection = show_menu("CleanupRL", options, 3);
		} else if ( strcmp(selection, "About") == 0 ) {
			show_dialog("About CleanupRL", about_lines, 3);
			selection = "Main";
		} else if ( strcmp(selection, "New Game") == 0 ) {
			selection = "Main";
		}

	} while ( strcmp(selection, "Quit") != 0 );

	endwin();

	return 0;
}
