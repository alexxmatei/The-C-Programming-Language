/*
 * Exercise_1-10.c
 *
 *  Created on: 28 Jan 2021
 *      Author: Al
 */

#include <stdio.h>

typedef unsigned char bool;

#define TRUE (bool)1u
#define FALSE (bool)0u

int main()
{
	int c;

	while ( ( c = getchar() ) != EOF )
	{
		bool flag = 0;

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

		if ( flag == FALSE )
		{
			(void)putchar(c);
		}
	}

	return 0;
}
