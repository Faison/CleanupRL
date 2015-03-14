#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "windows.h"

void render_player( Player *player, int y_offset, int x_offset ) {
	WINDOW *win = get_map_window();

	if (win == NULL) {
		return;
	}

	if (player == NULL) {
		return;
	}

	wmove( win, player->y + y_offset, player->x + x_offset );
	waddch( win, '@' );
}
