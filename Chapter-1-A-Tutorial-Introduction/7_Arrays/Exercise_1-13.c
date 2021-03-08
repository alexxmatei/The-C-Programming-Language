/*
 * Exercise_1-13.c
 *
 *  Created on: 12 Feb 2021
 *      Author: Al
 */

#include <stdio.h>
#include <math.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_WORD_LEN 20 /* maximum word length */
#define MIN_HIST_LEN 10 /* minimum histogram length */
/* ToDo Why does it bug out for high values? Example: 100. */
#define HIST_HEIGHT  20 /* height of the histogram */
#define DECIMAL_PRECISION 2
#define MIN_DECIMAL_VAL (1 / pow(10, DECIMAL_PRECISION)) /* get minimum decimal value based on precision */
#define MAX_PERCENTAGE 100
#define NR_OCCURRENCES_INDEX_WIDTH 2 /* maximum nr. width to be displayed under histogram drawing letter count index */
#define MAX_OCCURRENCES_INDEX_NR pow(10, NR_OCCURRENCES_INDEX_WIDTH)
#define S10_C 10 /* signed value constant */

/* printf format defines */
#define PRINTF_NR_WIDTH (DECIMAL_PRECISION + 3) /* the decimal precision plus the preceding "0." */
#define CHARS_BETWEEN_NR1_NR2 4 /* the number of characters between the 2 variables in the printf format string */
#define PRINTF_2ND_NR_WIDTH (DECIMAL_PRECISION + 3) /* the decimal precision plus the preceding "\d\d." */
#define CHARS_AFTER_NR2 3 /* "%:" and an extra space before the first symbol */
#define PRINTF_LEN PRINTF_NR_WIDTH + CHARS_BETWEEN_NR1_NR2 + PRINTF_2ND_NR_WIDTH + CHARS_AFTER_NR2 /* the length of the string before the 2nd percentage number */

/* prints a histogram of the lengths of words in input */
/* ToDo Clean up program, add functions, use variables instead of macros, document code */

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
				}
				else {
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
	for ( int i = HIST_HEIGHT; i >= 0; --i ) {
		if (i != 0) {
			prc[i - 1] = (int)((float)i / HIST_HEIGHT * MAX_PERCENTAGE);
		}
		if ( i != HIST_HEIGHT ) { /* skip the first and highest value, because we add an extra row at the end */
			/* if this is the first row */
			if (prc[i] == MAX_PERCENTAGE) {
				(void)printf("%*.*f%% - %*d%%: ", PRINTF_NR_WIDTH, DECIMAL_PRECISION, (float)prc[i - 1], PRINTF_2ND_NR_WIDTH, prc[i]);
			}
			/* else if this is the last row */
			else if ( i == 0 ) {
				(void)printf("%*.*f%% - %*.*f%%: ", PRINTF_NR_WIDTH, DECIMAL_PRECISION, MIN_DECIMAL_VAL, PRINTF_2ND_NR_WIDTH, DECIMAL_PRECISION, prc[i] - MIN_DECIMAL_VAL);
			}
			else {
				(void)printf("%*.*f%% - %*.*f%%: ", PRINTF_NR_WIDTH, DECIMAL_PRECISION, (float)prc[i - 1], PRINTF_2ND_NR_WIDTH, DECIMAL_PRECISION, prc[i] - MIN_DECIMAL_VAL);
			}
			for ( int j = 0; j < MAX_WORD_LEN; ++j ) {
				float ref = (float)i; /* reference */
				if ( i == 0 ) {
					ref = (float)MIN_DECIMAL_VAL;
				}
				/* the percentage of occurrences stored at the current index
				 * relative to the maximum number of occurrences */
				float prcOfMax = (float)histogram[j] / (float)max;
				/* scale the percentage (rounded down)
				 * based on the height of the histogram */
				float scaledPrc = (prcOfMax * (float)HIST_HEIGHT);
				if ( scaledPrc >= ref ) {
					(void)printf("%-3c", '#');
				}
				else {
					(void)printf("%-3c", '·');
				}
			}
		}
		(void)putchar('\n');
	}


	/* print spaces equal to the width of the percentage row
	 * this is so that the indexes are printed at the correct positions */
	for ( int i = 0; i < PRINTF_LEN; ++i ) {
		(void)putchar(' ');
	}

	/* print the indexes on the bottom of the histogram */
	for ( int i = 1; i <= MAX_WORD_LEN; ++i ) {
		/* each number is left-justified and has at minimum a width of 3 */
		(void)printf("%-3d", i);
	}

	if ( max < MAX_OCCURRENCES_INDEX_NR ) {
		(void)putchar('\n');
		/* print spaces equal to the width of the percentage row
		 * this is so that the indexes are printed at the correct positions */
		for ( int i = 0; i < PRINTF_LEN; ++i ) {
			(void)putchar(' ');
		}

		/* print the indexes on the bottom of the histogram */
		for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
			/* each number is left-justified and has at minimum a width of 3 */
			(void)printf("%-3d", histogram[i]);
		}
		(void)putchar('\n');
	}
	else {
		int lenWidth = 0;
		int maxWidth = MAX_WORD_LEN;
		(void)printf("\n\nNumber of occurrences:\n");

		while ( maxWidth != 0 ) {
			maxWidth /= S10_C;
			++ lenWidth;
		}

		for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
			(void)printf("%*d: %d\n", lenWidth, i + 1, histogram[i]);
		}
	}

	if ( biggerWords > 0 ) {
		(void)putchar('\n');
		(void)printf("Words larger than %d letters: %d", MAX_WORD_LEN, biggerWords);
	}

	return 0;
}
