#ifndef _SORT_MASS_STR
#define _SORT_MASS_STR


#define MAX_SIZE_STR 10
#define STR_COUNT 20
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.#?!;:`"


void GenerateStrings(char strings[][MAX_SIZE_STR]);
void PrintfStrings(char strs[][MAX_SIZE_STR]);
int compByLen(char* str1, char* str2);
int rev_compByLen(char* str1, char* str2);
void compByAlphabet(char* str1, char* str2);
void compByAlphabetWitjoutRegister(char* str1, char* str2);
void SortStrings(char strings[][MAX_SIZE_STR], void compareStringsFunction(char* str1, char* str2));


#endif // _SORT_MASS_STR

