#include <ncurses.h>
#include <string.h>
#include "menus.h"
#include "dialog.h"
#include "house.h"
#include "player.h"
#include "player_renderer.h"
#include "collision.h"

int main()
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	char *options[] = {"New Game", "About", "Quit"};
	char *selection = "Main";

	char *about_lines[] = {
		"Some text about things",
		"And other stuff when I care about",
		"other stuff."
	};

	int c = 0;

	House *house = NULL;
	Player *player = NULL;

	do {
		if ( strcmp(selection, "Main") == 0 ) {
			selection = show_menu("CleanupRL", options, 3);
		} else if ( strcmp(selection, "About") == 0 ) {
			show_dialog("About CleanupRL", about_lines, 3);
			selection = "Main";
		} else if ( strcmp(selection, "New Game") == 0 ) {
			house = generate_house();
			player = create_player();
			do {
				if (c == KEY_UP) {
					control_player(player, MOVE_UP);
				} else if (c == KEY_LEFT) {
					control_player(player, MOVE_LEFT);
				} else if (c == KEY_DOWN) {
					control_player(player, MOVE_DOWN);
				} else if (c == KEY_RIGHT) {
					control_player(player, MOVE_RIGHT);
				}
				clear();

				handle_player_collisions( player, house );

				resolve_player_control(player);

				display_house(house, 2, 2);
				render_player(player, 2, 2);

				refresh();
				c = getch();
			} while (c != '\n' );
			retire_player(player);
			demolish_house(house);
			selection = "Main";
		}

	} while ( strcmp(selection, "Quit") != 0 );

	endwin();

	return 0;
}
