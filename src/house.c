#include <ncurses.h>
#include <stdlib.h>
#include "house.h"

void display_room( Room *room, int y_offset, int x_offset );

House *generate_house()
{
	House *house = malloc(sizeof(House));

	if (house == NULL) {
		return NULL;
	}

	house->num_rooms = 8;
	house->rooms = malloc(house->num_rooms * sizeof(Room));

	if (house->rooms == NULL) {
		demolish_house(house);
		return NULL;
	}

	house->rooms[0].x = 0;
	house->rooms[0].y = 0;
	house->rooms[0].width = 24;
	house->rooms[0].height = 10;
	house->rooms[0].walls = CRL_FULL_WALLS;

	house->rooms[1].x = 23;
	house->rooms[1].y = 0;
	house->rooms[1].width = 14;
	house->rooms[1].height = 10;
	house->rooms[1].walls = CRL_FULL_WALLS;

	house->rooms[2].x = 0;
	house->rooms[2].y = 10;
	house->rooms[2].width = 37;
	house->rooms[2].height = 3;
	house->rooms[2].walls = CRL_WALL_LEFT | CRL_WALL_TOP_LEFT | CRL_WALL_BOTTOM_LEFT;

	house->rooms[3].x = 0;
	house->rooms[3].y = 13;
	house->rooms[3].width = 19;
	house->rooms[3].height = 8;
	house->rooms[3].walls = CRL_FULL_WALLS;

	house->rooms[4].x = 18;
	house->rooms[4].y = 13;
	house->rooms[4].width = 19;
	house->rooms[4].height = 8;
	house->rooms[4].walls = CRL_FULL_WALLS;

	house->rooms[5].x = 37;
	house->rooms[5].y = 10;
	house->rooms[5].width = 22;
	house->rooms[5].height = 11;
	house->rooms[5].walls = CRL_WALL_TOP_RIGHT | CRL_WALL_RIGHT | CRL_WALL_BOTTOM_RIGHT | CRL_WALL_BOTTOM | CRL_WALL_BOTTOM_LEFT;

	house->rooms[6].x = 37;
	house->rooms[6].y = 0;
	house->rooms[6].width = 11;
	house->rooms[6].height = 10;
	house->rooms[6].walls = CRL_WALL_TOP_LEFT | CRL_WALL_TOP | CRL_WALL_TOP_RIGHT;

	house->rooms[7].x = 48;
	house->rooms[7].y = 0;
	house->rooms[7].width = 11;
	house->rooms[7].height = 10;
	house->rooms[7].walls = CRL_FULL_WALLS & ~CRL_WALL_LEFT;

	return house;
}

void demolish_house( House *house )
{
	if (house == NULL) {
		return;
	}

	if (house->rooms != NULL) {
		free(house->rooms);
	}

	free(house);
}

void display_house( House *house, int y_offset, int x_offset )
{
	int i;

	clear();
	for (i = 0; i < house->num_rooms; i++) {
		display_room(house->rooms + i, y_offset, x_offset);
	}
	refresh();
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
