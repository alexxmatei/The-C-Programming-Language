/*
 * Exercise_1-16.c
 *
 *  Created on: 21 Apr 2021
 *      Author: Al
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getsline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
	int len;				/* current line length */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	for ( len = getsline(line, MAXLINE); len > 0; len = getsline(line, MAXLINE) ) {
		if ( len > max ) {
			max = len;
			copy(longest, line);
		}
	}
	if ( max > 0 ) { /* there was a line */
		(void)printf("Longest line: %s", longest);
		(void)printf("Length: %d", max);
		(void)printf(" (the '\\0' character is taken into account as well)");
	}
	return 0;
}

/* getsline: read a line into s, return length */
int getsline(char s[], int lim)
{
	int c;
	int i;
	int l_returnValue;

	for ( i = 0; (i < (lim - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i ) {
		s[i] = c;
	}
	if ( c == '\n' ) {
		s[i] = c;
		++i;
		l_returnValue = i;
	}
	else {
		l_returnValue = -1;
	}
	s[i] = '\0';
	return l_returnValue;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	for ( to[i] = from[i]; to[i] != '\0'; to[i] = from[i] ) {
		++i;
	}
}
