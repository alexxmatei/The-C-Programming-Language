/*
 * Fahrenheit-Celsius-Table.c
 *
 *  Created on: 27 Dec 2020
 *      Author: Al
 */

#include <stdio.h>

#define LOWER  0      /* lower limit of the table */
#define UPPER  300    /* upper limit */
#define STEP   20     /* step size */
#define F5_K   5.0f
#define F9_K   9.0f
#define S32_K  32

float fahrToCelsius(int fahr);

/* print Fahrenheit-Celsius table */
int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	{
		(void)printf("%3d %6.1f\n", fahr, fahrToCelsius(fahr));
	}

	return 0;
}

float fahrToCelsius(int fahr)
{
	return F5_K / F9_K * (fahr - S32_K);
}
