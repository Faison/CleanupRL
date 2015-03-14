#include <stdlib.h>
#include "windows.h"

WINDOW *map_window, *info_window, *log_window, *other_window;

void crl_refresh_window( WINDOW *window );
void crl_clear_window( WINDOW *window );
void crl_destroy_window( WINDOW *window );

WINDOW *get_map_window( void )
{
	return map_window;
}

WINDOW *get_info_window( void )
{
	return info_window;
}

void crl_create_windows( void )
{
	map_window = newwin(25, 65, 1, 1);
	info_window = newwin(25, 30, 1, 67);
	log_window = newwin(10, 30, 26, 67);
	other_window = newwin(10, 65, 26, 1);

	crl_refresh_window(map_window);
	crl_refresh_window(info_window);
	crl_refresh_window(log_window);
	crl_refresh_window(other_window);
}

void crl_destroy_windows( void )
{
	crl_destroy_window(map_window);
	crl_destroy_window(info_window);
	crl_destroy_window(log_window);
	crl_destroy_window(other_window);
}

void crl_clear_windows( void )
{
	crl_clear_window(map_window);
}

void crl_refresh_windows( void )
{
	crl_refresh_window(map_window);
}

void crl_destroy_window( WINDOW *window )
{
	if (window == NULL) {
		return;
	}

	wborder(window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(window);
	delwin(window);
}

void crl_clear_window( WINDOW *window )
{
	wclear(window);
}

void crl_refresh_window( WINDOW *window )
{
	wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(window);
}