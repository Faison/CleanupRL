#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "house.h"

void handle_player_collisions( Player *player, House *house ) {
	if (player == NULL || house == NULL) {
		return;
	}

	int new_x, new_y, valid = 1;

	new_x = player->x + player->x_velocity;
	new_y = player->y + player->y_velocity;

	Room *room = get_room_at_point( house, new_x, new_y);

	if (player->y_velocity != 0) {
		if (new_y == room->y) {
			if (new_x == room->x && room->walls & CRL_WALL_TOP_LEFT) {
				valid = 0;
			} else if (new_x + 1 == room->x + room->width && room->walls & CRL_WALL_TOP_RIGHT) {
				valid = 0;
			} else if (room->walls & CRL_WALL_TOP) {
				valid = 0;
			}
		} else if (new_y + 1 == room->y + room->height) {
			if (new_x == room->x && room->walls & CRL_WALL_BOTTOM_LEFT) {
				valid = 0;
			} else if (new_x + 1 == room->x + room->width && room->walls & CRL_WALL_BOTTOM_RIGHT) {
				valid = 0;
			} else if (room->walls & CRL_WALL_BOTTOM) {
				valid = 0;
			}
		}
	} else if (player->x_velocity != 0) {
		if (new_x == room->x) {
			if (new_y == room->y && room->walls & CRL_WALL_TOP_LEFT) {
				valid = 0;
			} else if (new_y + 1 == room->y + room->height && room->walls & CRL_WALL_BOTTOM_LEFT) {
				valid = 0;
			} else if (room->walls & CRL_WALL_LEFT) {
				valid = 0;
			}
		} else if (new_x + 1 == room->x + room->width ) {
			if (new_y == room->y && room->walls & CRL_WALL_TOP_RIGHT) {
				valid = 0;
			} else if (new_y == room->y + room->height && room->walls & CRL_WALL_BOTTOM_RIGHT) {
				valid = 0;
			} else if (room->walls & CRL_WALL_RIGHT) {
				valid = 0;
			}
		}
	}

	if (valid) {
		return;
	}

	player->x_velocity = 0;
	player->y_velocity = 0;
}
