#include <ncurses.h>
#include <string.h>

void show_menu_options( char *title, char *options[], int num_options );

/**
 * Displays a full screen menu and allows users to select between the options.
 *
 * @param char*   title The title to display above the menu.
 * @param char*[] An array of option strings.
 * @param int     The number of options to display.
 *
 * @return char* The options selected by the user.
 */
char *show_menu( char *title, char *options[], int num_options )
{
	int i, xpos = 0, xlef = 0, xri = 0, cursor_position = 0, c = 0;

	clear();
	show_menu_options( title, options, num_options );

	do {
		if (xlef > 0) {
			mvprintw(cursor_position + 5, xlef, " ");
			mvprintw(cursor_position + 5, xri, " ");
		}


		if (c == KEY_DOWN) {
			cursor_position++;
		} else if (c == KEY_UP) {
			cursor_position--;
		} else if (c == KEY_RESIZE) {
			clear();
			show_menu_options( title, options, num_options );
		}

		if (cursor_position >= num_options) {
			cursor_position = 0;
		} else if (cursor_position < 0) {
			cursor_position = num_options - 1;
		}

		xpos = (COLS - strlen(options[cursor_position])) / 2;
		xlef = xpos - 2;
		xri = xpos + strlen(options[cursor_position]) + 1;

		mvprintw(cursor_position + 5, xlef, ">");
		mvprintw(cursor_position + 5, xri, "<");
	} while ( (c = getch()) != '\n' );

	return options[cursor_position];
}

/**
 * Displays a full screen menu without any interaction.
 *
 * @param char*   title The title to display above the menu.
 * @param char*[] An array of option strings.
 * @param int     The number of options to display.
 */
void show_menu_options( char *title, char *options[], int num_options )
{
	int i, xpos = 0;

	xpos = (COLS - strlen(title)) / 2;
	mvprintw(2, xpos, "%s", title);

	for (i = 0; i < num_options; i++) {
		xpos = (COLS - strlen(options[i])) / 2;
		mvprintw(i + 5, xpos, "%s", options[i]);
	}
}