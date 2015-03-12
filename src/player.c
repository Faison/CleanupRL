#include <stdlib.h>
#include "player.h"

void control_player( Player *player, int action )
{
	if ( action == MOVE_UP ) {
		player->y_velocity--;
	} else if ( action == MOVE_RIGHT ) {
		player->x_velocity++;
	} else if ( action == MOVE_DOWN ) {
		player->y_velocity++;
	} else if ( action == MOVE_LEFT ) {
		player->x_velocity--;
	}
}

void resolve_player_control( Player *player )
{
	if ( player->y_velocity ) {
		player->y += player->y_velocity;
		player->y_velocity = 0;
	}

	if ( player->x_velocity ) {
		player->x += player->x_velocity;
		player->x_velocity = 0;
	}
}

Player *create_player( void )
{
	Player *player = malloc(sizeof(Player));

	if (player == NULL) {
		return NULL;
	}

	player->x = 11;
	player->y = 10;
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
