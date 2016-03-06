/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int i = 0, toInt, temp, a[12], j = 0, p;
	for (i = 0; i < afterdecimal; i++)
		number = number * 10;
	toInt = number;
	if (toInt < 0)
	{
		str[0] = '-';
		j++;
		toInt = -toInt;
	}
	i = 0;
	while (toInt != 0)
	{
		a[i] = toInt % 10;
		toInt = toInt / 10;
		i++;
	}
	for (p = i - 1; p >= afterdecimal; p--)
	{
		str[j] = a[p] + '0';
		j++;
	}
	if (afterdecimal > 0)
	{
		str[j++] = '.';
		while (afterdecimal > 0)
		{
			str[j++] = a[p--] + '0';
			afterdecimal--;
		}
		str[j] = '\0';
	}
	else
		str[j] = '\0';
}
