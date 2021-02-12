/*
 * Exercise_1-13.c
 *
 *  Created on: 12 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */

/* prints a histogram of the lengths of words in input */
int main()
{
	int c;
	int state = IN;
	int wl = 0; /* word length */

	for ( c = getchar(); c != EOF; c = getchar() ) {
		/* not a word, either a blank, tab or newline */
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) {
			/* if previous character was the end of a word */
			if ( state == IN ) {
				(void)printf("Word length is: %d\n", wl);
			}
			state = OUT;
		}
		/* start of a word */
		else if ( state == OUT ) {
			wl = 1;
			state = IN;
		}
		/* inside a word */
		else {
			++wl;
		}
	}

}
