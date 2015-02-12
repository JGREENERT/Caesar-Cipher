/*
** Author: Jesse Greenert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printTest(float[]);

/*
** Reads in frequencies from a given file
*/
void readFreq(float given[])
{
	
	FILE *fp = fopen("LetFreq.txt", "r");
	char buff[100] = " ";
	char* garbage = " ";
	char* freq = " ";
	int count = 0;
	while((fgets(buff, 100, fp)) != NULL)
	{
		garbage = strtok(buff, " ");
		freq = strtok(NULL, "\n");
		given[count] = atof(freq);
		count++;
	}
			
	fclose(fp);
}

/*
** Calculates frequencies of plain text given
** from a file. Converts all letters to uppercase
** before determining what letter it is
*/
void calcFreq(float found[])
{
	FILE *fp = fopen("SomeText.txt", "r");
	char buff = ' ';
	int totalChars = 0;
	while((buff = fgetc(fp)) != EOF)
	{
		if(isalpha(buff))
		{
			int temp = toupper(buff) - 65;
			found[temp]++;
			totalChars++;
		}
	}		

	for(int i = 0; i < 26; i++)
	{
		found[i] = (found[i]/totalChars);
	}
}

/*
** Moves to the next character in the alphabet
** 'num' places away. 
*/
char rotate(char ch, int num)
{
	char rotChar = toupper(ch);
	if((rotChar + num) > 90)
	{
		return ((rotChar + num - 90) + 64);
	}
	else
	{
		return rotChar + num;
	}
}

int findKey(float given[], float found[])
{
	
	return 0;
}

void decrypt(int key)
{


}
/*
** Was getting garbage values when trying to
** update arrays in the middle, so I made this 
** function to initially set all float values to 0.
*/
void initArray (float found[])
{
	for(int i = 0; i < 26; i++)
	{
		found[i] = 0;
	}
}

/*
** Helper function for printing what's inside of 
** the array of frequencies.
*/
void printTest(float toPrint[])
{	
	for(int i = 0; i < 26; i++)
	{
		 printf("%f\n", toPrint[i]);
	}
	printf("%c", '\n');
}

/*
** Main Method
*/
int main()
{
	float given[26];
	float found[26];
	initArray(found);
	readFreq(given); //Reading in known frequencies	
	//printTest(given); //Printing out Given
	calcFreq(found); //Finding character frequencies of file
	//printTest(found); //Printing out Found
	decrypt(findKey(given, found));
}


