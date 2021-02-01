/*
 * Exercise_1-12.c
 *
 *  Created on: 1 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1
#define OUT 0

/* ToDo: fix program so that it doesn't enter multiple newlines for multiple tabs, blanks or newlines */

/* prints given input, one word per line */
int main()
{
	int c;
	int state;
	c = 0;
	state = OUT;

	for ( c = getchar(); c != EOF; c = getchar() )
	{
		if ( (c == ' ') || (c == '\t') || (c == '\n') )
		{
			state = OUT;
			(void)putchar('\n');
		}
		else if ( state == OUT )
		{
			state = IN;
		}
		else
		{
			/* no action required */
		}

		if ( state == IN ) {
			(void)putchar(c);
		}
	}

	return 0;
}
