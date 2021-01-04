/*
 * CopyInputToOutput.c
 *
 *  Created on: 4 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* copy input to output; 1st version */
main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
