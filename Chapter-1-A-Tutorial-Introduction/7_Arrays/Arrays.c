/*
 * Arrays.c
 *
 *  Created on: 7 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define DIGITS_NR 10 /* number of digits 0 through 9 */

/* count digits, white space, others */
int main()
{
	int c;
	int i;
	int nwhite;
	int nother;
	int ndigit[DIGITS_NR];

	nwhite = nother = 0;
	for (i = 0; i < DIGITS_NR; ++i) {
		ndigit[i] = 0;
	}
	for ( c = getchar(); c != EOF; c = getchar() ) {
		if ( (c >= '0') && (c <= '9') ) {
			++ndigit[(char)c-(char)'0'];
		}
		else if ( (c == ' ') || (c == '\n') || (c == '\t') ) {
			++nwhite;
		}
		else {
			++nother;
		}
	}

	(void)printf("digits =");
	for (i = 0; i < DIGITS_NR; ++i) {
		(void)printf(" %d", ndigit[i]);
	}
	(void)printf(", white space = %d, other = %d\n",
		nwhite, nother);

	return 0;
}
