/** \file stringslib.c
*	\brief functions
*	
*	Details.
*/
#include "stringslib.h"

//da aggiungere commenti originali doxygen

void MOSstring(char* instr, int length, char* mos, int* occurrences) { // Most Occuring Symbol

	int freq[HIST_BINS]; // Store frequency of each symbol
	int i = 0;
	int max = 0;
	int ascii;

	/* Initializes frequency of all symbols to 0 */
	for (i = 0; i < HIST_BINS; i++)
		freq[i] = 0;

	/* Finds frequency of each symbol */
	i = 0;
	while (instr[i] != '\0' && i < length) // \0 è il fine stringa
	{
		ascii = (int)instr[i];
		freq[ascii] += 1;

		i++;
	}


	/* Finds maximum frequency */
	max = 0;
	for (i = 0; i < HIST_BINS; i++)
	{
		if (freq[i] > freq[max])
			max = i;
	}

	*mos = (char)max; // Così non cambio il puntatore ma solo il contenuto (è l'asterisco)
	*occurrences = freq[max];

	return;

}

int SOstring(char* instr, int length, char tosearch) {

	int i = 0;
	int occurrences = 0;

	while (instr[i] != '\0' && i < length)
	{
		if (instr[i] == tosearch)
			occurrences++;

		i++;
	}

	return occurrences;
}

int DOstring(char* instr, int length) {

	int i = 0;
	int occurrences = 0;

	while (instr[i] != '\0' && i < length)
	{
		if (instr[i] > 47 && instr[i] < 58) //Così accetto solo le cifre (in ASCII)
			occurrences++;

		i++;
	}

	return occurrences;
}

/*! @brief finds in a string the occurrences of alphabet characters
	@param instr string
	@param length of the string
	@return occurences of alphabet characters
*/
int AOstring(char* instr, int length) {

	int i = 0;
	int occurrences = 0;

	while (instr[i] != '\0' && i < length)
	{
		if ((instr[i] > 64 && instr[i] < 91) || (instr[i] > 96 && instr[i] < 123)) //Così accetto solo i caratteri (in ASCII)
			occurrences++;

		i++;
	}

	return occurrences;
}
