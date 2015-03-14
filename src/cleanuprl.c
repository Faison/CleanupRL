#include <string.h>
#include "screen.h"
#include "windows.h"
#include "menus.h"
#include "dialog.h"
#include "house.h"
#include "player.h"
#include "intent.h"
#include "collision.h"
#include "input.h"
#include "player_renderer.h"
#include "house_renderer.h"

int main()
{
	crl_init_screen();

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

			crl_create_windows();

			do {
				if (c == CRL_KEY_UP) {
					control_player(player, MOVE_UP);
				} else if (c == CRL_KEY_LEFT) {
					control_player(player, MOVE_LEFT);
				} else if (c == CRL_KEY_DOWN) {
					control_player(player, MOVE_DOWN);
				} else if (c == CRL_KEY_RIGHT) {
					control_player(player, MOVE_RIGHT);
				} else if (c == ' ') {
					control_player(player, INTERACT_NEAREST);
				}

				handle_player_intent( player, house );
				handle_player_collisions( player, house );

				resolve_player_control(player);

				crl_clear_windows();

				display_house(house, 2, 2);
				render_player(player, 2, 2);

				crl_refresh_windows();
				c = crl_get_ch();
			} while (c != '\n' );

			crl_destroy_windows();

			retire_player(player);
			demolish_house(house);

			selection = "Main";
		}

	} while ( strcmp(selection, "Quit") != 0 );

	crl_end_screen();

	return 0;
}
