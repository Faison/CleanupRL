#include <ncurses.h>

void crl_init_screen( void )
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
}

void crl_end_screen( void )
{
	endwin();
}

void crl_clear_screen( void )
{
	clear();
}

void crl_refresh_screen( void )
{
	refresh();
}
