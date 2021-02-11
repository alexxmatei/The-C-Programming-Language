/*
 * CharacterCounting.c
 *
 *  Created on: 16 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

/* count characters in input; 2nd version */
int main()
{
	double nc;

	for (nc = 0; getchar () != EOF; ++nc) {
		;
	}
	(void)printf("%.0f\n", nc);

	return 0;
}
