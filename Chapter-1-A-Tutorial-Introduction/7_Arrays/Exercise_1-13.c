/*
 * Exercise_1-13.c
 *
 *  Created on: 12 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */
#define MAX_WORD_LEN 20 /* maximum word length */
#define INDEX_WORD_LEN (i + 1)

/* prints a histogram of the lengths of words in input */
/* ToDo Optimise code if a good solution is found;
 * having to re-iterate through the whole array every time an action is performed takes a lot of time */
int main()
{
	int c;
	int state = IN;
	int wl = 0; /* word length */
	int histogram[MAX_WORD_LEN] = {0};

	/* ToDo why doesn't ((c != EOF) || (c != '*')) work ??? */
	for ( c = getchar(); c != EOF; c = getchar() ) {
		/* not a word, either a blank, tab or newline */
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) {
			/* if previous character was the end of a word */
			if ( state == IN ) {
				for (int i = 0; i < MAX_WORD_LEN; i++) {
					if( wl == INDEX_WORD_LEN ) {
						++histogram[i];
					}
				}
			}
			state = OUT;
		}
		/* start of a word */
		else if ( state == OUT ) {
			wl = 1;
			state = IN;
		}
		/* inside a word */
		else {
			++wl;
		}
	}

	for (int i = 0; i < MAX_WORD_LEN; ++i) {
		(void)printf("%2d:", INDEX_WORD_LEN);
		for(int j = 0; j < histogram[i]; ++j) {
			(void)putchar('#');
		}
		(void)putchar('\n');
	}

	return 0;
}
