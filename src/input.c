#include "input.h"

/**
 * Wrapper function for reading a character from the terminal window.
 *
 * @return int The character read from the window.
 */
int crl_get_ch( void )
{
	return getch();
}