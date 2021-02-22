/*
 * Exercise_1-13.c
 *
 *  Created on: 12 Feb 2021
 *      Author: Al
 */

#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_WORD_LEN 20 /* maximum word length */
#define MIN_HIST_LEN 10 /* minimum histogram length */
/* ToDo Why does it bug out for high values? Example: 100. */
#define HIST_HEIGHT  20 /* height of the histogram */

/* prints a histogram of the lengths of words in input */
/* ToDo Optimise code if a good solution is found;
 * having to re-iterate through the whole array
 * every time an action is performed takes a lot of time */
/* ToDo make histogram relative (MAXHIST = 15) book example
 * for example, if there is only 1 word, it will have the MAXHIST height
 * if there are 2 words, 1 of a fixed size, and another double that size
 * 1 will have MAXHIST height and 2 will have half that (rounded?) height */
/* ToDo Add percentage range index to each row of the histogram
 * Ex: 0 -  5% for the first
 *     5 - 10% for the second, and so on*/
/* ToDo Print the number of occurrences of the word length 
 * given by an index under each respective index
 * If this is done the spacing between histogram columns will have to adapt
 * to respect the width of the occurrences value for each index */
/* ToDo Also print a table with occurrences */
int main()
{
	int c;
	int state = IN;
	int wl = 0; /* word length */
	int max = 0; /* maximum occurrence of word */
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

	/* find the maximum occurrences of a word */
	for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
		if ( max < histogram[i] ) {
			max = histogram[i];
		}
	}

	int prc[HIST_HEIGHT] = { 0 };
	/* go through the top of the histogram to the bottom */
	for ( int i = HIST_HEIGHT; i > 0; --i ) {
		prc[i - 1] = (int)((float)i/HIST_HEIGHT*100);
		if (prc[i - 1] == 100) {
			(void)printf("%12d%%: ", prc[i - 1]);
		}
		else {
			(void)printf("%3d%% - %5.2f%%: ", prc[i], (int)((float)(i+1)/HIST_HEIGHT*100)-0.01 );
		}
		for ( int j = 0; j < MAX_WORD_LEN; ++j ) {
			/* the percentage of occurrences stored at the current index
			 * relative to the maximum number of occurrences */
			float prcOfMax = (float)histogram[j] / (float)max;
			/* scale the percentage (rounded down)
			 * based on the height of the histogram */
			int scaledPrc = (int)(prcOfMax * (float)HIST_HEIGHT);
			if (scaledPrc >= i) {
				(void)printf("%-3c", '#');
			}
			else {
				(void)printf("%-3c", '·');
			}
		}
		(void)putchar('\n');
	}

	#define PERCENTAGE_TEXT_WIDTH 15
	/* print spaces equal to the width of the percentage row
	 * this is so that the indexes are printed at the correct positions */
	for (int i = 0; i < PERCENTAGE_TEXT_WIDTH; ++i) {
		(void)putchar(' ');
	}

	/* print the indexes on the bottom of the histogram */
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
