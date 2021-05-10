/*
 * Exercise_1-16.c
 *
 *  Created on: 9 May 2021
 *      Author: Al
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
typedef char bool;
#define TRUE  (bool) 1u
#define FALSE (bool) 0u

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
		(void)printf("%s", longest);
	}
	return 0;
}

/* getsline: read a line into s, return length */
int getsline(char s[], int lim)
{
	int c;
	int i;
	bool l_loopCondition_b = TRUE;

	for ( i = 0; l_loopCondition_b == TRUE; ++i ) {
		c = getchar();
		l_loopCondition_b = ((i < (lim - 1)) && (c != EOF) && (c != '\n'));
		printf("%d", l_loopCondition_b);
		s[i] = c;
	}
	if ( c == '\n' ) {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
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
