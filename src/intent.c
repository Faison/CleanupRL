#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "house.h"

void handle_player_intent( Player *player, House *house )
{
	int n_features;
	Room_Feature *features[4];

	if (player->intent == INTERACT_NEAREST) {
		n_features = get_features_near_point(features, house, player->x, player->y, 4);
		if (n_features == 1) {
			interact_with_room_feature(*features);
		}
	}

	player->intent = 0;
}
