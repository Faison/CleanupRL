#ifndef CRL_PLAYER_H
#define CRL_PLAYER_H

typedef struct _crl_player {
	int x;
	int y;
	int x_velocity;
	int y_velocity;
} Player;

enum CRL_Actions {
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT
};

Player *create_player( void );
void retire_player( Player *player );
void control_player( Player *player, int action );
void resolve_player_control( Player *player );

#endif
