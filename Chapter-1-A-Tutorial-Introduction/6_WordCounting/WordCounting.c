/*
 * WordCounting.c
 *
 *  Created on: 29 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

/* count lines, words, and characters in input */
int main()
{
	int c;
	int nl;
	int nw;
	int nc;
	int state;

	state = OUT;
	nl = nw = nc = 0;
	for ( c = getchar(); c != EOF; c = getchar() ) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if ( (c == ' ') || (c == '\n') || (c == '\t') ) {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		else {
			/* no action required */
		}
	}
	(void)printf("%d %d %d\n", nl, nw, nc);

	return 0;
}
