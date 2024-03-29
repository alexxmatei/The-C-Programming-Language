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
#define MAX_WORD_LEN 20 /* maximum word length tracked by the histogram */
#define HIST_HEIGHT  20 /* height of the histogram */
#define DECIMAL_PRECISION 2 /* the number of decimals used for the percentages */
#define MIN_DECIMAL_VAL (1 / pow(10, DECIMAL_PRECISION)) /* get minimum decimal value based on precision */
#define MAX_PERCENTAGE 100
#define MAX_NR_WIDTH (int)log10(MAX_PERCENTAGE) + 1 /* obtain the max number width based on the widest number, the maximum percentage */
#define MAX_OCCURRENCES_INDEX_NR 99 /* the maximum number to be displayed as an index under the histogram */
#define S10_C 10 /* signed value constant */

/* printf format defines */
#define PRINTF_NR_1_WIDTH (DECIMAL_PRECISION + MAX_NR_WIDTH + 1) /* the number plus the '.' */
#define CHARS_BETWEEN_NR1_NR2 4 /* the number of characters between the 2 numbers in the printf format string: "% - " */
#define PRINTF_NR_2_WIDTH (DECIMAL_PRECISION + MAX_NR_WIDTH + 1) /* the number plus the '.' */
#define CHARS_AFTER_NR2 3 /* the number of characters after the 2nd number in the printf format string: "%: " */
#define PRINTF_TEXT_LEN PRINTF_NR_1_WIDTH + CHARS_BETWEEN_NR1_NR2 + PRINTF_NR_2_WIDTH + CHARS_AFTER_NR2

/* prints a histogram of the lengths of words in input */
int main()
{
	int c;
	int state = IN; /* current state relative to a word */
	int wl = 0; /* word length */
	int max = 0; /* maximum occurrence of word */
	int histogram[MAX_WORD_LEN] = { 0 }; /* initialise the array with 0 */
	int biggerWords = 0; /* count the words larger than MAX_WORD_LEN */

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

	{
		int prc[HIST_HEIGHT] = { 0 };
		/* go through the top of the histogram to the bottom */
		for ( int i = HIST_HEIGHT; i >= 0; --i ) {
			if ( i != 0 ) {
/* ignore -Wconversion for the line between the #pragma statements */
/* Justification: the conversion is intended */
#pragma GCC diagnostic push /* remember state of the diagnostics before changes */
#pragma GCC diagnostic ignored "-Wconversion"
				prc[i - 1] = (int)((float)i / HIST_HEIGHT * MAX_PERCENTAGE);
#pragma GCC diagnostic pop /* restore state of the diagnostics before changes */
			}
			if ( i != HIST_HEIGHT ) { /* skip the first and highest value, because we add an extra row at the end */
				/* if this is the first row */
				if ( prc[i] == MAX_PERCENTAGE ) {
					(void)printf("%*.*f%% - %*.*f%%: ",
								 PRINTF_NR_1_WIDTH, DECIMAL_PRECISION, (float)prc[i - 1],
								 PRINTF_NR_2_WIDTH, DECIMAL_PRECISION, (float)prc[i]);
				}
				/* else if this is the last row */
				else if ( i == 0 ) {
					(void)printf("%*.*f%% - %*.*f%%: ",
								 PRINTF_NR_1_WIDTH, DECIMAL_PRECISION, MIN_DECIMAL_VAL,
								 PRINTF_NR_2_WIDTH, DECIMAL_PRECISION, prc[i] - MIN_DECIMAL_VAL);
				}
				else {
					(void)printf("%*.*f%% - %*.*f%%: ",
								 PRINTF_NR_1_WIDTH, DECIMAL_PRECISION, (float)prc[i - 1],
								 PRINTF_NR_2_WIDTH, DECIMAL_PRECISION, prc[i] - MIN_DECIMAL_VAL);
				}
				for ( int j = 0; j < MAX_WORD_LEN; ++j ) {
					float ref = (float)i; /* reference */
					if ( i == 0 ) {
						/* instead of 0 take the minimum decimal value as reference */
						/* this way values with 0 occurrences will be ignored, 
						 * they will not be drawn as a '#' symbol in the last row */
						ref = (float)MIN_DECIMAL_VAL;
					}
					/* the percentage of occurrences stored at the current index
					 * relative to the maximum number of occurrences */
					float prcOfMax = (float)histogram[j] / (float)max;
					/* scale the percentage (rounded down)
					 * based on the height of the histogram */
					float scaledPrc = (prcOfMax * (float)HIST_HEIGHT);
					/* draw the histogram symbols for each row/column */
					if ( scaledPrc >= ref ) {
						(void)printf("%-3c", '#');
					}
					else {
						(void)printf("%-3c", '�');
					}
				}
			}
			(void)putchar('\n');
		}
	}

	/* print spaces equal to the width of the percentage row
	 * this is so that the indexes are printed at the correct positions */
	for ( int i = 0; i < PRINTF_TEXT_LEN; ++i ) {
		(void)putchar(' ');
	}

	/* print the indexes on the bottom of the histogram */
	for ( int i = 1; i <= MAX_WORD_LEN; ++i ) {
		/* each number is left-justified and has at minimum a width of 3 */
		(void)printf("%-3d", i);
	}

	/* prints the word occurrence for each word width indicated by the index */
	/* if the maximum number of occurrences is small enough,
	 * this is done right below the index row */
	if ( max <= MAX_OCCURRENCES_INDEX_NR ) {
		(void)putchar('\n');
		/* print spaces equal to the width of the percentage row
		 * this is so that the indexes are printed at the correct positions */
		for ( int i = 0; i < PRINTF_TEXT_LEN; ++i ) {
			(void)putchar(' ');
		}

		/* print the indexes on the bottom of the histogram */
		for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
			/* each number is left-justified and has at minimum a width of 3 */
			(void)printf("%-3d", histogram[i]);
		}
		(void)putchar('\n');
	}
	/* if the maximum number of occurrences is too big,
	 * a separate table is printed below the histogram */
	else {
		int indexWidth = 0;
		int maxIndex = MAX_WORD_LEN;
		(void)printf("\n\nNumber of occurrences:\n");

		while ( maxIndex != 0 ) {
			maxIndex /= S10_C;
			++ indexWidth;
		}

		for ( int i = 0; i < MAX_WORD_LEN; ++i ) {
			(void)printf("%*d: %d\n", indexWidth, i + 1, histogram[i]);
		}
	}

	/* if there are any numbers bigger than MAX_WORD_LEN, print how many there are */
	if ( biggerWords > 0 ) {
		(void)putchar('\n');
		(void)printf("Words larger than %d letters: %d", MAX_WORD_LEN, biggerWords);
	}

	return 0;
}
