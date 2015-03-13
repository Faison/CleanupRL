#include <ncurses.h>
#include "house.h"

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

	base_y = y_offset + room->y;

	for (y = 0; y < room->height; y++) {
		move(base_y + y, x_offset + room->x);

		for (x = 0; x < room->width; x++) {
			if (y == 0) {
				if (x == 0) {
					if (room->walls & CRL_WALL_TOP_LEFT) {
						if (room->walls & CRL_WALL_LEFT && room->walls & CRL_WALL_TOP) {
							addch(ACS_ULCORNER);
						} else if (room->walls & CRL_WALL_LEFT) {
							addch(ACS_VLINE);
						} else if (room->walls & CRL_WALL_TOP) {
							addch(ACS_HLINE);
						} else {
							addch(ACS_DIAMOND);
						}
					} else {
						addch('.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_TOP_RIGHT) {
						if (room->walls & CRL_WALL_RIGHT && room->walls & CRL_WALL_TOP) {
							addch(ACS_URCORNER);
						} else if (room->walls & CRL_WALL_RIGHT) {
							addch(ACS_VLINE);
						} else if (room->walls & CRL_WALL_TOP) {
							addch(ACS_HLINE);
						} else {
							addch(ACS_DIAMOND);
						}
					} else {
						addch('.');
					}
				} else {
					if (room->walls & CRL_WALL_TOP) {
						addch(ACS_HLINE);
					} else {
						addch('.');
					}
				}
			} else if (y == room->height - 1) {
				if (x == 0) {
					if (room->walls & CRL_WALL_BOTTOM_LEFT) {
						if (room->walls & CRL_WALL_LEFT && room->walls & CRL_WALL_BOTTOM) {
							addch(ACS_LLCORNER);
						} else if (room->walls & CRL_WALL_LEFT) {
							addch(ACS_VLINE);
						} else if (room->walls & CRL_WALL_BOTTOM) {
							addch(ACS_HLINE);
						} else {
							addch(ACS_DIAMOND);
						}
					} else {
						addch('.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_BOTTOM_RIGHT) {
						if (room->walls & CRL_WALL_RIGHT && room->walls & CRL_WALL_BOTTOM) {
							addch(ACS_LRCORNER);
						} else if (room->walls & CRL_WALL_RIGHT) {
							addch(ACS_VLINE);
						} else if (room->walls & CRL_WALL_BOTTOM) {
							addch(ACS_HLINE);
						} else {
							addch(ACS_DIAMOND);
						}
					} else {
						addch('.');
					}
				} else {
					if (room->walls & CRL_WALL_BOTTOM) {
						addch(ACS_HLINE);
					} else {
						addch('.');
					}
				}
			} else {
				if (x == 0) {
					if (room->walls & CRL_WALL_LEFT) {
						addch(ACS_VLINE);
					} else {
						addch('.');
					}
				} else if (x == room->width - 1) {
					if (room->walls & CRL_WALL_RIGHT) {
						addch(ACS_VLINE);
					} else {
						addch('.');
					}
				} else {
					addch('.');
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

	if (feature->type == CRL_DOOR_FEATURE) {
		if (feature->state == CRL_CLOSE_STATE) {
			f = '+';
		} else if (feature->state == CRL_OPEN_STATE) {
			f = '.';
		}
	}

	if (f) {
		mvaddch( feature->y + y_offset, feature->x + x_offset, f );
	}
}
