#ifndef CRL_WINDOWS_H
#define CRL_WINDOWS_H

#include <ncurses.h>

WINDOW *get_map_window( void );

WINDOW *get_info_window( void );

void crl_create_windows( void );

void crl_destroy_windows( void );

void crl_clear_windows( void );

void crl_refresh_windows( void );

void crl_refresh_all_windows( void );

#endif
