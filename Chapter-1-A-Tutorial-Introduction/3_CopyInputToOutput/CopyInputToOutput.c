/*
 * CopyInputToOutput.c
 *
 *  Created on: 4 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* copy input to output; 2nd version */
int main()
{
	int c;

	while ( ( c = getchar() ) != EOF ) {
		(void)putchar(c);
	}

	return 0;
}
