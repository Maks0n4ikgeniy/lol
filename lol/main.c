#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "strmass.h"


int main()
{
	//void(*compareStringsFunction[4])(char*, char*) = { compByAlphabet, compByAlphabetWitjoutRegister, (void*)rev_compByLen, (void*)compByLen };
	srand((unsigned int)time(0));
	char strings[STR_COUNT][MAX_SIZE_STR];
	GenerateStrings(strings);
	PrintfStrings(strings);
//	SortStrings(strings, compByAlphabet);
	return 0;
}