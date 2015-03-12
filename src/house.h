#ifndef CRL_HOUSE_H
#define CRL_HOUSE_H

enum CRL_Wall {
	CRL_WALL_TOP_LEFT     = (1 << 0),
	CRL_WALL_TOP          = (1 << 1),
	CRL_WALL_TOP_RIGHT    = (1 << 2),
	CRL_WALL_RIGHT        = (1 << 3),
	CRL_WALL_BOTTOM_RIGHT = (1 << 4),
	CRL_WALL_BOTTOM       = (1 << 5),
	CRL_WALL_BOTTOM_LEFT  = (1 << 6),
	CRL_WALL_LEFT         = (1 << 7),
	CRL_FULL_WALLS        = CRL_WALL_TOP_LEFT | CRL_WALL_TOP | CRL_WALL_TOP_RIGHT | CRL_WALL_RIGHT |
							CRL_WALL_BOTTOM_RIGHT | CRL_WALL_BOTTOM | CRL_WALL_BOTTOM_LEFT | CRL_WALL_LEFT
};

typedef struct _crl_house {
	int width;
	int height;
	struct _crl_room *rooms;
	int num_rooms;
} House;

typedef struct _crl_room {
	int x;
	int y;
	int width;
	int height;
	int walls;
} Room;

House *generate_house();
void demolish_house( House *house );
void display_house( House *house, int y_offset, int x_offset );

#endif
