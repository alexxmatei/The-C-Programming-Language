/*
 * CopyInputToOutput.c
 *
 *  Created on: 4 Jan 2021
 *      Author: Al
 *
 *  Exercise: Verify that the expression getchar() != EOF is - or 1.
 */

#include <stdio.h>
typedef unsigned char bool;

/* copy input to output; 2nd version */
int main()
{
	int c;
	bool expressionValue;

	while ( ( expressionValue = ( (c = getchar()) != EOF ) ) != 0 )
	{
		(void)printf("\nFor the following character:'");
		(void)putchar(c);
		(void)printf("', with the value %3d the expression value is: %u\n", c, expressionValue);
	}
	(void)printf("For the following character: ");
	(void)putchar(c);
	(void)printf(", with the value %3d the expression value is: %u\n", c, expressionValue);

	return 0;
}
