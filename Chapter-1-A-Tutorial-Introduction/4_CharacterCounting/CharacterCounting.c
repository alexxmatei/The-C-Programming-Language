/*
 * CharacterCounting.c
 *
 *  Created on: 16 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
	double nc;

	for (nc = 0; getchar () != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
