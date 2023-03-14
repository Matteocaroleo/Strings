/** \file stringslib.h
*	\prototypes
* 
*	Details.
*/
#pragma once
#define HIST_BINS 256 

#ifndef STRINGSLIB_H
#define STRINGSLIB_H



void MOSstring(char* instr, int length, char* mos, int* occurrences); // Most Occuring Symbol



int SOstring(char* instr, int length, char tosearch);


int DOstring(char* instr, int length);


int AOstring(char* instr, int length);
#endif