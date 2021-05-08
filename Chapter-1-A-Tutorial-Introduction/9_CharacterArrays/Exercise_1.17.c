/*
 * Exercise_1.17.c
 *
 *  Created on: 7 May 2021
 *      Author: Al
 */

#include <stdio.h>
#define MAXLINE 1000 		/* maximum input line size */
#define PRINTED_LINE_LEN 80	/* the length of lines to be printed */

int getsline(char line[], int maxline);

/* print all lines over 80 characters input line */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	for ( len = getsline(line, MAXLINE); len > 0; len = getsline(line, MAXLINE) ) {
		if ( len > PRINTED_LINE_LEN ) {
			(void)printf("%s", line);
		}
	}
	return 0;
}

/* getsline: read a line into s, return length */
int getsline(char s[], int lim)
{
	int c;
	int i;

	for ( i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i ) {
		s[i] = c;
	}
	if ( c == '\n' ) {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
