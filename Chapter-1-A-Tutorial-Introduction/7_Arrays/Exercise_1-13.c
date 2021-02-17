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
/* ToDo make histogram relative (MAXHIST = 15) book example
 * for example, if there is only 1 word, it will have the MAXHIST height
 * if there are 2 words, 1 of a fixed size, and another double that size
 * 1 will have MAXHIST height and 2 will have half that (rounded?) height */
int main()
{
	int c;
	int state = IN;
	int wl = 0; /* word length */
	/* maximum occurrence of word, 10 is default
	 * so that histogram is at least 10 characters high */
	int max = MIN_HIST_LEN;
	int histogram[MAX_WORD_LEN] = { 0 }; /* initialise the array with 0 */
	int biggerWords = 0; /* count the words larger than MAX_WORD_LEN */

	/* ToDo why doesn't ((c != EOF) || (c != '*')) work ??? */
	for ( c = getchar(); c != EOF; c = getchar() ) {
		/* not a word, either a blank, tab or newline */
		if ( (c == ' ') || (c == '\t') || (c == '\n') ) {
			/* if previous character was the end of a word */
			if ( state == IN ) {
					if ( wl <= MAX_WORD_LEN ) {
						++histogram[wl - 1];
					} else {
						++biggerWords;
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
	for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
		if ( max < histogram[i] ) {
			max = histogram[i];
		}
	}

	/* go through the top of the histogram to the bottom */
	for ( int i = max; i > 0; --i ) {
		for ( int j = 0; j < MAX_WORD_LEN; ++j ) {
			/* if the occurrences are bigger or equal than
			 * the occurrences for that line, print a '#' for that position */
			if ( histogram[j] >= i ) {
				(void)printf("%-3c", '#');
			}
			else {
				(void)printf("%-3c", '·');
			}
		}
		(void)putchar('\n');
	}

	/* print the word length numbers on the bottom of the histogram */
	for ( int j = 1; j <= MAX_WORD_LEN; ++j ) {
		/* each number is left-justified and has at minimum a width of 3 */
		(void)printf("%-3d", j);
	}

	if ( biggerWords > 0 ) {
		(void)putchar('\n');
		(void)putchar('\n');
		(void)printf("Words larger than %d letters: %d", MAX_WORD_LEN, biggerWords);
	}

	return 0;
}

