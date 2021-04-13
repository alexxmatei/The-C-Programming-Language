/*
 * Exercise_1-14.c
 *
 *  Created on: 26 Mar 2021
 *      Author: Al
 */

#include <stdio.h>
#include <math.h>

typedef unsigned char bool;

#define TRUE  (bool)1u
#define FALSE (bool)0u

#define MAX_CHARACTERS_TRACKED 5 /* maximum characters tracked by the histogram */
#define HIST_HEIGHT  20 /* height of the histogram */
#define DECIMAL_PRECISION 2 /* the number of decimals used for the percentages */
#define MIN_DECIMAL_VAL (1 / pow(10, DECIMAL_PRECISION)) /* get minimum decimal value based on precision */
#define MAX_PERCENTAGE 100
#define MAX_PERCENTAGE_NR_WIDTH (int)log10(MAX_PERCENTAGE) + 1 /* obtain the width of the maximum percentage number */
#define MAX_OCCURRENCES_INDEX_NR 99 /* the maximum number to be displayed as an index under the histogram */
#define S10_C 10 /* signed value constant */

/* printf format defines */
#define PRINTF_NR_1_WIDTH (DECIMAL_PRECISION + MAX_PERCENTAGE_NR_WIDTH + 1) /* the number plus the '.' */
#define CHARS_BETWEEN_NR1_NR2 4 /* the number of characters between the 2 numbers in the printf format string: "% - " */
#define PRINTF_NR_2_WIDTH (DECIMAL_PRECISION + MAX_PERCENTAGE_NR_WIDTH + 1) /* the number plus the '.' */
#define CHARS_AFTER_NR2 3 /* the number of characters after the 2nd number in the printf format string: "%: " */
#define PRINTF_TEXT_LEN PRINTF_NR_1_WIDTH + CHARS_BETWEEN_NR1_NR2 + PRINTF_NR_2_WIDTH + CHARS_AFTER_NR2

void swap(int *xp, int *yp);
void reverseBubbleSort(int arr[], int arr2[], int n);

/* prints a histogram of the character occurrence frequency in input */
int main()
{
	int c;
	int max = 0; /* maximum occurrence of character */
	int histogram[MAX_CHARACTERS_TRACKED] = { 0 }; /* initialise the array with 0 */
	int characters[MAX_CHARACTERS_TRACKED];
	/* initialise the characters array with -1 */
	for (int i = 0; i < MAX_CHARACTERS_TRACKED; ++i) {
		characters[i] = -1;
	}
	/* keep track of any extra characters that do not fit in the characters array
	 * if a new character is found while the array is full (MAX_CHARACTERS_TRACKED elements)
	 * it will be tracked in this variable */
	int untrackedCharacters = 0;
	int totalCharactersTracked = 0; /* keep track how many different characters are stored in the characters array */

	for ( c = getchar(); c != EOF; c = getchar() ) {
		/* not a blank, tab or newline */
		if ( (c != ' ') && (c != '\t') && (c != '\n') ) {
			bool charExists_b = FALSE;
			for ( int i = 0; i < MAX_CHARACTERS_TRACKED; ++i ) {
				if ( c == characters[i] ) {
					charExists_b = TRUE;
					++histogram[i];
				}
			}
			if ( charExists_b == FALSE ) {
				if ( totalCharactersTracked < MAX_CHARACTERS_TRACKED ) {
					++totalCharactersTracked;
					/* initialise first new character */
					if ( characters[0] == -1 ) {
						characters[0] = c;
						++histogram[0];
					}
					else {
						int i = 0;
						/* find the first available index in the characters array */
						for ( /* nothing */; (i < MAX_CHARACTERS_TRACKED) && (characters[i] != -1); ++i ) {
						};
						/* store the new character at that index */
						characters[i] = c;
						++histogram[i];
					}
				}
				else {
					++untrackedCharacters;
				}
			}
		}
	}

	/* after processing inputs, sort the histogram and character arrays */
	/* the arrays are sorted based on the character occurrence frequency stored in the histogram array */
	reverseBubbleSort(histogram, characters, totalCharactersTracked);

	/* find the maximum occurrences of a character */
	for ( int i = 0; i < totalCharactersTracked; ++i ) {
		if ( max < histogram[i] ) {
			max = histogram[i];
		}
	}

	/* draw the histogram */
	{
		int prc[HIST_HEIGHT] = { 0 };
		if ( totalCharactersTracked > 0 ) {
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
					for ( int j = 0; j < totalCharactersTracked; ++j ) {
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
							(void)printf("%-3c", '·');
						}
					}
				}
				(void)putchar('\n');
			}
		}
		else {
			(void)printf("No characters read from input.");
		}
	}

	/* print spaces equal to the width of the percentage row
	 * this is so that the indexes are printed at the correct positions */
	for ( int i = 0; i < PRINTF_TEXT_LEN; ++i ) {
		(void)putchar(' ');
	}

	/* print the indexes on the bottom of the histogram */
	for ( int i = 0; i < totalCharactersTracked; ++i ) {
		/* each number is left-justified and has at minimum a width of 3 */
		(void)printf("%-3c", characters[i]);
	}

	/* prints the character occurrence frequency as a number indicated by an index */
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
		for ( int i = 0; i < totalCharactersTracked; ++i ) {
			/* each number is left-justified and has at minimum a width of 3 */
			(void)printf("%-3d", histogram[i]);
		}
		(void)putchar('\n');
	}
	/* if the maximum number of occurrences is too big,
	 * a separate table is printed below the histogram */
	else {
		int indexWidth = 0;
		int maxIndex = totalCharactersTracked;
		(void)printf("\n\nNumber of occurrences:\n");

		while ( maxIndex != 0 ) {
			maxIndex /= S10_C;
			++ indexWidth;
		}

		for ( int i = 0; i < totalCharactersTracked; ++i ) {
			(void)printf("%*c: %d\n", indexWidth, characters[i], histogram[i]);
		}
	}

	/* if there are any untracked characters, print how many there are */
	if ( untrackedCharacters > 0 ) {
		(void)putchar('\n');
		(void)printf("Untracked characters: %d", untrackedCharacters);
	}

	return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* A function to implement reverse (high to low) bubble sort
   It sorts the first array based on its values, from highest to lowest
   The second array is sorted based on the values of the first array
   Therefore the values in the second array are not taken into account */
void reverseBubbleSort(int arr[], int arr2[], int n)
{
   int i;
   int j;
   for (i = 0; i < (n - 1); i++) {
       /* Last i elements are already in place */
       for (j = 0; j < (n - i - 1); j++) {
           if (arr[j] < arr[j+1]) {
              swap(&arr[j], &arr[j+1]);
              swap(&arr2[j], &arr2[j+1]);
           }
       }
   }
}
