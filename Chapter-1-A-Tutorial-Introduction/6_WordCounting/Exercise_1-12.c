/*
 * Exercise_1-12.c
 *
 *  Created on: 1 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

/* prints given input, one word per line */
int main()
{
	int c;
	int state = OUT;

	for ( c = getchar(); c != EOF; c = getchar() ) {
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) { /* not inside a word */
			if ( state == IN ) { /* the end of a word */
				state = OUT;
				(void)putchar('\n');
			}
		}
		else if ( state == OUT ) { /* start of a word */
			state = IN;
			(void)putchar(c);
		}
		else { /* inside a word */
			(void)putchar(c);
		}
	}

	return 0;
}
