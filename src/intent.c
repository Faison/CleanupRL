#include <stdlib.h>
#include <ncurses.h>
#include "player.h"
#include "house.h"
#include "input.h"

void handle_player_intent( Player *player, House *house )
{
	int i, c, selection = -1, n_features, max_features = 8;
	Room_Feature *features[max_features];

	for (i = 0; i < max_features; i++) {
		features[i] = NULL;
	}

	if (player->intent == INTERACT_NEAREST) {
		n_features = get_features_near_point(features, house, player->x, player->y, max_features);
		if (n_features == 1) {
			for (i = 0; i < max_features; i++) {
				if ( features[i] != NULL) {
					interact_with_room_feature(features[i]);
					break;
				}
			}
		} else if (n_features > 1) {
			do {
				mvprintw(30, 10, "Which direction to interact?");
				c = crl_get_ch();

				if (c == CRL_KEY_UP && features[0] != NULL) {
					selection = 0;
				} else if (c == CRL_KEY_RIGHT && features[1] != NULL) {
					selection = 1;
				} else if (c == CRL_KEY_DOWN && features[2] != NULL) {
					selection = 2;
				} else if (c == CRL_KEY_LEFT && features[3] != NULL) {
					selection = 3;
				}

			} while (selection == -1 && c != 'q');

			if (selection >= 0) {
				interact_with_room_feature(features[selection]);
			}
		}
	}

	player->intent = 0;
}
