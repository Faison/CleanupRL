#include <stdlib.h>
#include "player.h"

void control_player( Player *player, int action )
{
	if ( action == MOVE_UP ) {
		player->y--;
	} else if ( action == MOVE_RIGHT ) {
		player->x++;
	} else if ( action == MOVE_DOWN ) {
		player->y++;
	} else if ( action == MOVE_LEFT ) {
		player->x--;
	}
}

Player *create_player( void )
{
	Player *player = malloc(sizeof(Player));

	if (player == NULL) {
		return NULL;
	}

	player->x = 11;
	player->y = 6;
	player->x_velocity = 0;
	player->y_velocity = 0;

	return player;
}

void retire_player( Player *player )
{
	if (player == NULL) {
		return;
	}

	free(player);
}