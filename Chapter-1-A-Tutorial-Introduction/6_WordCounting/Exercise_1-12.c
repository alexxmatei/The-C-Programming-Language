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
	int c = 0;
	int lc = 0; /* line counter, counts number of consecutive newlines outputted */
	int state = OUT;

	for ( c = getchar(); c != EOF; c = getchar() )
	{
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) /* not inside a word */
		{
			++lc;
			state = OUT;
			if ( lc <= 1 )
			{
				(void)putchar('\n');
			}
		}
		else if ( state == OUT ) /* start of a word */
		{
			state = IN;
		}
		else
		{
			/* no action required */
		}

		if ( state == IN ) /* inside a word */
		{
			lc = 0;
			(void)putchar(c);
		}
	}

	return 0;
}
