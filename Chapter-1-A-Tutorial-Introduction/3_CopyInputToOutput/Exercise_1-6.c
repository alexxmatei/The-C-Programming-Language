/*
 * CopyInputToOutput.c
 *
 *  Created on: 4 Jan 2021
 *      Author: Al
 */

#include <stdio.h>
typedef unsigned char bool;

/* copy input to output; 2nd version */
main()
{
	int c;
	bool expressionValue;

	while ( ( expressionValue = ( (c = getchar()) != EOF ) ) != 0 )
	{
		printf("\nFor the following character:'");
		putchar(c);
		printf("', with the value %3d the expression value is: %u\n", c, expressionValue);
	}
	printf("For the following character: ");
	putchar(c);
	printf(", with the value %3d the expression value is: %u\n", c, expressionValue);
}
