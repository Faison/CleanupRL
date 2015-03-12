#include <ncurses.h>
#include "player.h"

void render_player( Player *player, int y_offset, int x_offset ) {
	mvaddch( player->y + y_offset, player->x + x_offset, '@' );
}
