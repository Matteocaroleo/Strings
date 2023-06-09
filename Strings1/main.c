/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/

/*! \mainpage All you need to know about Strings
*
* \section intro_sec Introduction
*
* This is the introduction.
*
* \section install_sec Installation
*
* \subsection step1 Step 1: Opening the box
*
* etc...
*/

#include <stdio.h> 
#include <stdlib.h> 
#include "stringslib.h"

#define STR_SIZE 1000



int main() {

	int hist[HIST_BINS] = {0};
	char str[STR_SIZE];
	char outstr[STR_SIZE];
	char mos;
	int occurrences;
	char tosearch;


	printf("Enter text: ");
	if (fgets(str, STR_SIZE, stdin) == NULL) {
		printf("ERROR in Main: cannot read input text\n");
		return -1;

	str[strcspn(str, "\n")] = 0; // removes EOL from the string

	}
	printf("\nstring: %s\n", str);
	Shist(str, STR_SIZE, hist);
	MOSstring(hist, &mos, &occurrences); // Glie le passo per reference, cos� che possa scriverci direttamente
	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(hist);
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(hist);
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	tosearch = getchar();
	occurrences = SOstring(hist, tosearch);

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);


	return 0;
}