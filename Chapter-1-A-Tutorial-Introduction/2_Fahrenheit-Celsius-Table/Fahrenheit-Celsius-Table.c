/*
 * Fahrenheit-Celsius-Table.c
 *
 *  Created on: 27 Dec 2020
 *      Author: Al
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300 */

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	while (fahr <= upper) {
     /* celsius = (fahr - 32) * (5 / 9) is incorrect,
      * the result of the operation would be 0 because (5 / 9) is integer division
      * and the result would be truncated of the fractional part */
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
