/*
 * Fahrenheit-Celsius-Table.c
 *
 *  Created on: 27 Dec 2020
 *      Author: Al
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
 *  for celsius = 0, 20, ..., 300; floating-point version */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	printf("Celsius  Fahrenheit\n"); /* prints a header to the table */
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%5.0f %11.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
