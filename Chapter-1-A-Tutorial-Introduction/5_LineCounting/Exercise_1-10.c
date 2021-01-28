/*
 * Exercise_1-10.c
 *
 *  Created on: 28 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

int main()
{
	int c;
	char flag = 0;

	while ( ( c = getchar() ) != EOF )
	{
		flag = 0;

		if ( c == '\t' )
		{
			flag = 1;
			(void)putchar('\\');
			(void)putchar('t');
		}

		if ( c == '\b' )
		{
			flag = 1;
			(void)putchar('\\');
			(void)putchar('b');
		}

		if ( c == '\\' )
		{
			flag = 1;
			(void)putchar('\\');
		}

		if ( flag == 0 )
		{
			(void)putchar(c);
		}
	}

	return 0;
}
