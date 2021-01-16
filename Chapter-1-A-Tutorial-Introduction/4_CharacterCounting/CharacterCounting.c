/*
 * CharacterCounting.c
 *
 *  Created on: 16 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count characters in input; 1st version */
main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
