/*
 * LineCounting.c
 *
 *  Created on: 20 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count lines in input */
int main()
{
	int c;
	int nl;

	nl = 0;
	for ( c = getchar(); c != EOF; c = getchar() )
	{
		if (c == '\n')
		{
			++nl;
		}
	}
	(void)printf("%d\n", nl);

	return 0;
}
