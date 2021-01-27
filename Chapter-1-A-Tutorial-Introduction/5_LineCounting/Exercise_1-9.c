/*
 * Exercise_1-9.c
 *
 *  Created on: 27 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* copy input to output, replacing multiple sequential blanks with a single one */
int main()
{
	int c;
	int bc = 0; /* blank counter */

	while ( (c = getchar() ) != EOF )
	{
		if ( c == ' ' )
		{
			++bc;
		}

		if ( c != ' ' )
		{
			bc = 0;
		}

		if ( bc <= 1 )
		{
			(void)putchar(c);
		}
	}

	return 0;
}
