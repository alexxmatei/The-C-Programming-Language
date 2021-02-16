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
#define MIN_HIST_LEN 10 /* minimum histogram length */

/* prints a histogram of the lengths of words in input */
/* ToDo Optimise code if a good solution is found;
 * having to re-iterate through the whole array
 * every time an action is performed takes a lot of time */
int main()
{
	int c;
	int state = IN;
	int wl = 0; /* word length */
	/* maximum occurrence of word, 10 is default
	 * so that histogram is at least 10 characters high */
	int max = MIN_HIST_LEN;
	int histogram[MAX_WORD_LEN] = {0}; /* initialise the array with 0 */

	/* ToDo why doesn't ((c != EOF) || (c != '*')) work ??? */
	for ( c = getchar(); c != EOF; c = getchar() ) {
		/* not a word, either a blank, tab or newline */
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) {
			/* if previous character was the end of a word */
			if ( state == IN ) {
				for (int i = 0; i < MAX_WORD_LEN; i++) {
					if( wl == (i + 1) ) {
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

	/* find the maximum occurrences of a word, if it is bigger than 10 */
	for (int i = 0; i < MAX_WORD_LEN; ++i) {
		if (max < histogram[i]) {
			max = histogram[i];
		}
	}

	/* go through the top of the histogram to the bottom */
	for (int i = max; i > 0; --i) {
		for (int j = 0; j < MAX_WORD_LEN; ++j) {
			/* if the occurrences are bigger or equal than
			 * the occurrences for that line, print a '#' for that position */
			if (histogram[j] >= i) {
				(void)printf("%-3c", '#');
			}
			else {
				(void)printf("%-3c", '·');
			}
		}
		(void)putchar('\n');
	}

	/* print the word length numbers on the bottom of the histogram */
	for (int j = 1; j <= MAX_WORD_LEN; ++j) {
		/* each number is left-justified and has at minimum a width of 3 */
		(void)printf("%-3d", j);
	}

	return 0;
}

