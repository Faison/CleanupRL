#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "house.h"

void handle_player_intent( Player *player, House *house )
{
	int i, n_features, max_features = 8;
	Room_Feature *features[max_features];

	for (i = 0; i < max_features; i++) {
		features[i] = NULL;
	}

	if (player->intent == INTERACT_NEAREST) {
		n_features = get_features_near_point(features, house, player->x, player->y, max_features);
		if (n_features > 0) {
			interact_with_room_feature(features[0]);
		}
	}

	player->intent = 0;
}
