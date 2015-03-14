#ifndef CRL_INPUT_H
#define CRL_INPUT_H

#include <ncurses.h>

enum CRL_Key {
	CRL_KEY_UP     = KEY_UP,
	CRL_KEY_RIGHT  = KEY_RIGHT,
	CRL_KEY_DOWN   = KEY_DOWN,
	CRL_KEY_LEFT   = KEY_LEFT,
	CRL_KEY_RESIZE = KEY_RESIZE
};

int crl_get_ch( void );

#endif
