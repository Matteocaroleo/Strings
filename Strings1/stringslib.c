/** \file stringslib.c
*	\brief functions definitions
*	
*	Details.
*/
#include "stringslib.h"
#include <stdio.h>


/** \brief Histogram function
*	\param instr Input string
*	\param length String length
*	\param hist Histogram (pointer to)
*/
void Shist(char* instr, int length, int* hist) {
	if (hist == NULL) {
		printf("Error: null pointer");
		return;
	}
	int i = 0;
	
	int ascii;

	/* Initializes frequency of all symbols to 0 */
	for (i = 0; i < HIST_BINS; i++)
		hist[i] = 0;
	/* Finds frequency of each symbol */
	i = 0;
	while (instr[i] != '\0' && i < length) // \0 è il fine stringa
	{
		ascii = (int)instr[i];
		hist[ascii] += 1;

		i++;
	}

};	
/*! @brief finds most occurent ASCII symbol in a string
	@param hist Histogram (pointer to)
	@param mos Most occurring character (pointer to)
	@param occurrences frequency of the moc (pointer to)
*/
void MOSstring(int* hist, char* mos, int* occurrences){ // Most Occuring Symbol
	int i = 0;
	int max = 0;
	/* Finds maximum frequency */
	max = 0;
	for (i = 0; i < HIST_BINS; i++)
	{
		if (hist[i] > hist[max])
			max = i;
	}

	*mos = (char)max; // Così non cambio il puntatore ma solo il contenuto (è l'asterisco)
	*occurrences = hist[max];

	return;

}
/*! @brief finds in a string the occurrences of a given ASCII symbol
	@param hist Histogram (pointer to)
	@param tosearch the character
	@return occurences of the character
*/
int SOstring(int* hist, char tosearch){
	int i = 0;
	int occurrences = 0;

	while (i < HIST_BINS)
	{
		if (i == (int)tosearch)
		{ 
			occurrences= hist[i];
			return occurrences;
		}
		i++;
	}

	return occurrences;
}
/*! @brief finds in a string the occurrences of digits
	@param instr string
	@param length of the string
	@return occurences of digits
*/
int DOstring(int* hist) {

	int i = 0;
	int occurrences = 0;

	while (i < HIST_BINS)
	{
		if ((i > 47 && i < 58)&& (hist [i] > 0)) //Così accetto solo le cifre (in ASCII)
			occurrences++;

		i++;
	}

	return occurrences;
}

/*! @brief finds in a string the occurrences of alphabet characters
	@param hist Histogram (pointer to)
	@return occurences of alphabet characters
*/
int AOstring(int* hist) {

	int i = 0;
	int occurrences = 0;

	while (i < HIST_BINS)
	{
		if (((i > 64 && i < 91)&& (hist[i] > 0)) || ((i > 96 && i < 123)&& (hist[i] > 0))) //Così accetto solo i caratteri (in ASCII)
			occurrences++;

		i++;
	}

	return occurrences;
}
