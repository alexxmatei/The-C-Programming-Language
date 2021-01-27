/*
 * Exercise_1-8.c
 *
 *  Created on: 26 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count blanks, tabs, and newlines in input */
int main()
{
	int c;
	int b = 0;
	int t = 0;
	int nl = 0;

	while ( ( c = getchar() ) != EOF )
	{
		if ( c == ' ' )
		{
			++b;
		}

		if ( c == '\t' )
		{
			++t;
		}

		if ( c == '\n' )
		{
			++nl;
		}
	}
	(void)printf("\nNumber of blanks: %d\nNumber of tabs: %d\nNumber of newlines: %d\n", b, t, nl);
	return 0;
}
