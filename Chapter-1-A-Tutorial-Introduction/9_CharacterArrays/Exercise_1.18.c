/*
 * Exercise_1-16.c
 *
 *  Created on: 9 May 2021
 *      Author: Al
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getsline(char line[], int maxline);

/* mirrors user input, removes trailing blanks, tabs and removes blank lines */
int main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	for ( len = getsline(line, MAXLINE); len > 0; len = getsline(line, MAXLINE) ) {
		/* start from len - 2 skipping the '\n' & '\0' characters at the end */
		/* eliminate all trailing blanks and tab characters */
		for ( int i = len - 2; (line[i] == ' ') || (line[i] == '\t'); --i) {
			line[i] = line[i + 1]; /* move '\n' character to the ' ' or '\t' character position */
			line[i + 1] = line [i + 2]; /* move the '\0' character to the previous '\n' position */
		}
		/* if not a blank line (ignore, therefore delete entirely blank lines) */
		if ( (len != 1) && (line[0] != '\n') ) {
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
