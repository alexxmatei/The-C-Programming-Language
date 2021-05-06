/*
 * Exercise_1-16.c
 *
 *  Created on: 21 Apr 2021
 *      Author: Al
 */

#include <stdio.h>
#include <string.h>
#define MAXINPUTLINE 1000 				/* maximum input line size */
#define MAXLINE (MAXINPUTLINE + 2) 	/* maximum array size (includes the \n character) */
#define MAXLENSIZE (MAXLINE - 1) 	/* maximum line size, does not include the \0 character */

int getsline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
	int len;					/* current line length */
	int max;					/* maximum length seen so far */
	int savedLen;				/* keeps track of the length of arbitrarily long lines */
	char line[MAXLINE];			/* current input line up to MAXLENSIZE limit */
	char longest[MAXLINE];		/* longest line saved here */
	char startOfLine[MAXLINE];	/* stores the the first MAXLENSIZE characters of a line */

	max = savedLen = 0;
	for ( len = getsline(line, MAXLINE); len > 0; len = getsline(line, MAXLINE) ) {
		savedLen += len;
		/* condition only valid at the start of a new line */
		/* this is to avoid unnecessarily calling the copy function */
		if ( savedLen == len ) {
			copy(startOfLine, line);
		}

		if ( (savedLen > max) ) {
			max = savedLen;
			if ( strncmp(longest, startOfLine, MAXLINE) != 0 ) {
				copy(longest, startOfLine);
			}
		}

		/* if this is the end of the line */
		if ( (len != MAXLENSIZE) || (line[MAXLINE - 2] == '\n') ) {
			savedLen = 0;
		}
	}

	if ( max > 0 ) { /* there was a line */
		(void)printf("Longest line: %s\n", longest);
		(void)printf("Length: %d", max);
		(void)printf(" (the '\\n' character is taken into account as well)");
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	for ( to[i] = from[i]; to[i] != '\0'; to[i] = from[i] ) {
		++i;
	}
}
