#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strmass.h"


void GenerateString(char *str, unsigned max_size)
{
	if (max_size == 0)
	{
		fprintf(stderr, "ERROR! Lenght not be 0!");
		exit(0);
	}
	unsigned int size = rand() % max_size + 1, j = 0;
	if (size > MAX_SIZE_STR)
	{
		fprintf(stderr, "ERROR! Generated lenght greater then MAX!");
		exit(0);
	}
	for (j = 0; j < size; ++j)
	{
		str[j] = ALPHABET[rand() % 69];
	}
	if (size != MAX_SIZE_STR)
	{
		str[j] = '\0';
	}
}

void GenerateStrings(char strings[][MAX_SIZE_STR])
{
	for (int i = 0; i < STR_COUNT; ++i)
	{
		GenerateString(strings[i], 10);
	}
}

void PrintfStrings(char strs[][MAX_SIZE_STR])
{
	for (int i = 0; i < STR_COUNT; ++i)
	{
		printf("[%d] ", i+1);
		for (int j = 0; j < MAX_SIZE_STR; ++j)
		{
			if (strs[i][j] == '\0')
			{
				printf("%c", strs[i][j]);
				break;
			}
			printf("%c", strs[i][j]);
		}
		printf("\n");
	}
}

int my_strlen(char* str)
{
	int i = 0, len = 0;
	while (str[i] != '\0' && i < MAX_SIZE_STR)
	{
		++i;
		++len;
	}
	return len;
}

int my_strcmp(char* str1, char* str2)
{
	for (int i = 0; i < MAX_SIZE_STR; ++i)
	{
		if (str1[i] > str2[i])
			return 1;
		if (str1[i] < str2[i])
			return -1;
	}
	return 0;
}



int my_stricmp(char* str1, char* str2) 
{
	int len1 = my_strlen(str1), len2 = my_strlen(str2), ind_str1[MAX_SIZE_STR], ind_str2[MAX_SIZE_STR], j = 0, k = 0;
	for (int i = 0; i < (len1 > len2 ? len1 : len2); ++i)
	{
		if (str1[i] >= 0x41 && str1[i] <= 0x5A)
		{
			str1[i] = str1[i] + ('a' - 'A');
			ind_str1[j++] = i;
		}
		if (str2[i] >= 0x41 && str2[i] <= 0x5A)
		{
			str2[i] = str2[i] + ('a' - 'A');
			ind_str2[k++] = i;
		}
	}
	int n = my_strcmp(str1, str2);
	k = 0; j = 0;
	for (int i = 0; i < (len1 > len2 ? len1 : len2); ++i)
	{
		if (i == ind_str1[j])
		{
			str1[i] = str1[i] - ('a' - 'A');
			++j;
		}
		if (i == ind_str2[k])
		{
			str2[i] = str2[i] - ('a' - 'A');
			++k;
		}
	}
	return n;
}

char* my_strcpy(char* str1, char* str2)
{
	char* ptr = str1;
	int  i = 0;
	while (i < MAX_SIZE_STR)
	{
		*str1++ = *str2++;
		++i;
	}
	return ptr;
}

int compByLen(char *str1, char *str2)
{
	int l = strlen(str1);
	int r = strlen(str2);
	if (l < r)
	{
		return 1;
	}
	else if (l > r)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int rev_compByLen(char* str1, char* str2)
{
	int l = strlen(str1);
	int r = strlen(str2);
	if (l < r)
	{
		return -1;
	}
	else if (l > r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void compByAlphabet(char* str1, char* str2)
{
	char tmp[MAX_SIZE_STR];
	if (my_strcmp(str1, str2) > 0)
	{
		my_strcpy(tmp, str1);
		my_strcpy(str1, str2);
		my_strcpy(str2, tmp);
	}
}

void compByAlphabetWitjoutRegister(char* str1, char* str2)
{
	char tmp[MAX_SIZE_STR];
	if (my_stricmp(str1, str2) > 0)
	{
		my_strcpy(tmp, str1);
		my_strcpy(str1, str2);
		my_strcpy(str2, tmp);
	}
}


void SortStrings(char strings[][MAX_SIZE_STR], void compareStringsFunction(char* str1, char* str2))
{
	int i = 0;
	int j = STR_COUNT - 1;

	char *mid = strings[STR_COUNT / 2];

	do {
		while (my_strcmp(strings[i], mid) < 0) {
			i++;
		}
		while (my_strcmp(strings[j], mid) > 0) {
			j--;
		}

		if (i <= j) {
			compareStringsFunction(strings[i], strings[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {

		SortStrings(strings[j][MAX_SIZE_STR], compareStringsFunction);
	}
	if (i < STR_COUNT) {
		SortStrings(strings[i][MAX_SIZE_STR], compareStringsFunction);
	}
}
