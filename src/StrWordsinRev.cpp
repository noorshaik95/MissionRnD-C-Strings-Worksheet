/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>
void word_reverse(char *input, int i)
{
	char temp;
	int k, j;
	j = i;
	for (i; input[i] != ' '; i++)
	{
		if (input[i] == '\0')
			break;
	}
	k = i + 1;
	while (j<i)
	{
		temp = input[j];
		input[j] = input[i - 1];
		input[i - 1] = temp;
		j++;
		i--;
	}
	if (input[k - 1] == '\0')
		return;
	else
		word_reverse(input, k);
}
void str_words_in_rev(char *input, int len){
	int i = 0;
	char temp;
	while (i < len)
	{
		temp = input[i];
		input[i] = input[len - 1];
		input[len - 1] = temp;
		len--;
		i++;
	}

	word_reverse(input, 0);
}

