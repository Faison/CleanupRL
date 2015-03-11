#include <ncurses.h>
#include "player.h"

void render_player( Player *player ) {
	mvaddch( player->y, player->x, '@' );
}