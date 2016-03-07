/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	int i = 0;
	if (str == '\0' || str == "" || K<0)
		return '\0';
	for (i = 0; str[i]; i++);
	if (K > (i-1))
		return '\0';
	return str[i-K-1];

	
}