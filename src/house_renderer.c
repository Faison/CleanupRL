#include <stdlib.h>
#include <ncurses.h>
#include "house.h"
#include "windows.h"

void display_room( Room *room, int y_offset, int x_offset );
void display_room_features( Room *room, int y_offset, int x_offset );
void display_feature( Room_Feature *feature, int y_offset, int x_offset );

void display_house( House *house, int y_offset, int x_offset )
{
	int i;

	if (house == NULL) {
		return;
	}

	for (i = 0; i < house->num_rooms; i++) {
		display_room(house->rooms + i, y_offset, x_offset);
		display_room_features(house->rooms + i, y_offset, x_offset);
	}
}

void display_room( Room *room, int y_offset, int x_offset )
{
	int y, x, i, width, base_y;
	WINDOW *win = get_map_window();

	if (win == NULL) {
		return;
	}

	base_y = y_offset + room->y;

	for (y = 0; y < room->height; y++) {
		wmove(win, base_y + y, x_offset + room->x);

		for (x = 0; x < room->width; x++) {
			if (y == 0) {
				if (x == 0) {
					if (room->walls & CRL_WALL_TOP_LEFT) {
						if (room->walls & CRL_WALL_LEFT && room->walls & CRL_WALL_TOP) {
							waddch(win, ACS_ULCORNER);
						} else if (room->walls & CRL_WALL_LEFT) {
							waddch(win, ACS_VLINE);
						} else if (room->walls & CRL_WALL_TOP) {
							waddch(win, ACS_HLINE);
						} else {
							waddch(win, ACS_DIAMOND);
						}
					} else {
						waddch(win, '.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_TOP_RIGHT) {
						if (room->walls & CRL_WALL_RIGHT && room->walls & CRL_WALL_TOP) {
							waddch(win, ACS_URCORNER);
						} else if (room->walls & CRL_WALL_RIGHT) {
							waddch(win, ACS_VLINE);
						} else if (room->walls & CRL_WALL_TOP) {
							waddch(win, ACS_HLINE);
						} else {
							waddch(win, ACS_DIAMOND);
						}
					} else {
						waddch(win, '.');
					}
				} else {
					if (room->walls & CRL_WALL_TOP) {
						waddch(win, ACS_HLINE);
					} else {
						waddch(win, '.');
					}
				}
			} else if (y == room->height - 1) {
				if (x == 0) {
					if (room->walls & CRL_WALL_BOTTOM_LEFT) {
						if (room->walls & CRL_WALL_LEFT && room->walls & CRL_WALL_BOTTOM) {
							waddch(win, ACS_LLCORNER);
						} else if (room->walls & CRL_WALL_LEFT) {
							waddch(win, ACS_VLINE);
						} else if (room->walls & CRL_WALL_BOTTOM) {
							waddch(win, ACS_HLINE);
						} else {
							waddch(win, ACS_DIAMOND);
						}
					} else {
						waddch(win, '.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_BOTTOM_RIGHT) {
						if (room->walls & CRL_WALL_RIGHT && room->walls & CRL_WALL_BOTTOM) {
							waddch(win, ACS_LRCORNER);
						} else if (room->walls & CRL_WALL_RIGHT) {
							waddch(win, ACS_VLINE);
						} else if (room->walls & CRL_WALL_BOTTOM) {
							waddch(win, ACS_HLINE);
						} else {
							waddch(win, ACS_DIAMOND);
						}
					} else {
						waddch(win, '.');
					}
				} else {
					if (room->walls & CRL_WALL_BOTTOM) {
						waddch(win, ACS_HLINE);
					} else {
						waddch(win, '.');
					}
				}
			} else {
				if (x == 0) {
					if (room->walls & CRL_WALL_LEFT) {
						waddch(win, ACS_VLINE);
					} else {
						waddch(win, '.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_RIGHT) {
						waddch(win, ACS_VLINE);
					} else {
						waddch(win, '.');
					}
				} else {
					waddch(win, '.');
				}
			}
		}
	}
}

void display_room_features( Room *room, int y_offset, int x_offset )
{
	int i;

	if (room == NULL) {
		return;
	}

	y_offset += room->y;
	x_offset += room->x;

	for (i = 0; i < room->num_features; i++) {
		display_feature(room->features + i, y_offset, x_offset);
	}
}

void display_feature( Room_Feature *feature, int y_offset, int x_offset )
{
	char f = '\0';
	WINDOW *win = get_map_window();

	if (win == NULL) {
		return;
	}

	if (feature->type == CRL_DOOR_FEATURE) {
		if (feature->state == CRL_CLOSE_STATE) {
			f = '+';
		} else if (feature->state == CRL_OPEN_STATE) {
			f = '.';
		}
	}

	if (f) {
		wmove( win, feature->y + y_offset, feature->x + x_offset );
		waddch( win, f );
	}
}
