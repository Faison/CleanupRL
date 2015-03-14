#include <ncurses.h>

void crl_init_screen()
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
}

void crl_end_screen()
{
	endwin();
}

void crl_clear_screen()
{
	clear();
}

void crl_refresh_screen()
{
	refresh();
}
