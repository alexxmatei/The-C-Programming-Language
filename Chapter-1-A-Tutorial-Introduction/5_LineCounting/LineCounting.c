/*
 * LineCounting.c
 *
 *  Created on: 20 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count lines in input */

main()
{
	int c, nl;

	nl = 0;
	while ((c=getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
