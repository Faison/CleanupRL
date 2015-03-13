#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "house.h"

void handle_player_collision_with_features( Player *player, Room *room );
void handle_player_collision_with_walls( Player *player, Room *room );

void handle_player_collisions( Player *player, House *house ) {
	if (player == NULL || house == NULL) {
		return;
	}

	Room *room = get_room_at_point( house, player->x + player->x_velocity, player->y + player->y_velocity);

	handle_player_collision_with_features(player, room);
	handle_player_collision_with_walls(player, room);
}

void handle_player_collision_with_features( Player *player, Room *room )
{
	if (player == NULL || room == NULL) {
		return;
	}

	int new_x, new_y, valid = 1;

	new_x = player->x + player->x_velocity;
	new_y = player->y + player->y_velocity;

	Room_Feature *feature = get_feature_at_point(room, new_x, new_y);

	if (feature == NULL) {
		return;
	}

	if (feature->type == CRL_DOOR_FEATURE) {
		if (feature->state == CRL_CLOSE_STATE) {
			interact_with_room_feature(feature);
			player->x_velocity = 0;
			player->y_velocity = 0;
		} else if (feature->state == CRL_OPEN_STATE) {
			player->x += player->x_velocity;
			player->y += player->y_velocity;
			player->x_velocity = 0;
			player->y_velocity = 0;
		}
	}
}

void handle_player_collision_with_walls( Player *player, Room *room )
{
	if (player == NULL || room == NULL) {
		return;
	}

	int new_x, new_y, valid = 1;

	new_x = player->x + player->x_velocity;
	new_y = player->y + player->y_velocity;

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

	if (valid) {
		return;
	}

	player->x_velocity = 0;
	player->y_velocity = 0;
}
