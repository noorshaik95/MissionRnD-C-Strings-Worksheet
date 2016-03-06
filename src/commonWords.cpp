/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int valid(char *str1, char *str2, int first, int last)
{
	int i = first, j, count = 0;
	for (j = 0; str2[j] != '\0'; j++)
	{
		if (str2[j] == str1[i])
		{
			count++;
			i++;
			if (count == (last - first))
				return 1;
		}
		else
		{
			count = 0;
			i = first;
		}

	}
	return 0;
}

char ** commonWords(char *str1, char *str2) {
	int i, j = 0, first = 0, last = 0, p = 0, q = 0, k, flag = 0;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char **result = (char **)malloc(SIZE * sizeof(char *));
	for (i = 0; i < SIZE; i++)
		result[i] = (char *)malloc(SIZE * sizeof(char));
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == ' ')
		{
			last = i;
			j = valid(str1, str2, first, last);
			if (j == 1)
			{
				flag = 1;
				for (k = first; k < last; k++)
				{
					result[p][q++] = str1[k];
				}
				result[p][q] = '\0';
				q = 0;
				p++;
			}
			first = last + 1;
			j = 0;
		}
	}
	first = last + 1;
	last = i;
	j = valid(str1, str2, first, last);
	if (j == 1)
	{
		flag = 1;
		for (k = first; k < last; k++)
		{
			result[p][q++] = str1[k];
		}
		result[p][q] = '\0';
		p++;
		q = 0;
	}
	if (flag != 1)
		return NULL;
	else
		return result;
}