/*
 * Functions.c
 *
 *  Created on: 18 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define S2_K  2
#define S3_K  3
#define N3_K  -3
#define S10_K 10

int power(int m, int n);

/* test power function */
int main()
{
	int i;

	for (i = 0; i < S10_K; ++i) {
		(void)printf("%d %d %d\n", i, power(S2_K,i), power(N3_K,i));
	}
	return 0;
}

/* power: raise base to n-th power; n >= 0; version 2 */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n) {
		p = p * base;
	}
	return p;
}
