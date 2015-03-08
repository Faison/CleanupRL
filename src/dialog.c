#include <ncurses.h>
#include <string.h>

void show_dialog_text( char *title, char *lines[], int num_lines );

/**
 * Displays a full screen Dialog and waits for the user to escape it.
 *
 * @param char*   title The title to display above the dialog.
 * @param char*[] An array of lines of text.
 * @param int     The number of lines to display.
 *
 * @return char* The options selected by the user.
 */
void show_dialog( char *title, char *lines[], int num_lines )
{
	int c;

	show_dialog_text( title, lines, num_lines );

	while ( (c = getch()) != ' ' ) {
		if (c == KEY_RESIZE) {
			clear();
			show_dialog_text( title, lines, num_lines );
		}
	}
}

/**
 * Displays a full screen Dialog with a title and lines of text.
 *
 * @param char*   title The title to display above the dialog.
 * @param char*[] An array of lines of text.
 * @param int     The number of lines to display.
 *
 * @return char* The options selected by the user.
 */
void show_dialog_text( char *title, char *lines[], int num_lines ) {
	int i, xpos, len, longest = 0, c;

	clear();
	xpos = (COLS - strlen(title)) / 2;
	mvprintw(2, xpos, "%s", title);

	for (i = 0; i < num_lines; i++) {
		len = strlen(lines[i]);
		if ( len > longest ) {
			longest = len;
		}
	}

	xpos = (COLS - longest) / 2;

	for (i = 0; i < num_lines; i++) {
		mvprintw(i + 5, xpos, "%s", lines[i]);
	}

	mvprintw(num_lines + 7, xpos, "SPACE to go back");
}