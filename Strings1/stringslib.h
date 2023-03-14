/** \file stringslib.h
*	\ brief Functions declarations
* 
*	Details.
*/
#pragma once


#ifndef STRINGSLIB_H
#define STRINGSLIB_H
#define HIST_BINS 256 

void Shist(char* instr, int lenght, int* hist);	//nuova funzione che crea un istogramma
void MOSstring(int* hist, char* mos, int* occurrences); // Most Occuring Symbol
int SOstring(int* hist, char tosearch);
int DOstring(int* hist);
int AOstring(int* hist);
#endif