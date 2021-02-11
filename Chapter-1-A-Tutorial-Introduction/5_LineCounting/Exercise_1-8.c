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
	int nb = 0; /* number of blanks */
	int nt = 0; /* number of tabs */
	int nl = 0; /* number of newlines */

	for ( c = getchar(); c != EOF; c = getchar() ) {
		if ( c == ' ' ) {
			++nb;
		}

		if ( c == '\t' ) {
			++nt;
		}

		if ( c == '\n' ) {
			++nl;
		}
	}
	(void)putchar('\n');
	(void)printf("Number of blanks:   %d\n", nb);
	(void)printf("Number of tabs:     %d\n", nt);
	(void)printf("Number of newlines: %d\n", nl);
	return 0;
}
