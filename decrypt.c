/*
** Author: Jesse Greenert
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void printTest(float[]);

/*
** Reads in frequencies from a given file
*/
void readFreq(float given[])
{
	
	FILE *fp = fopen("LetFreq.txt", "r");
	char buff[100] = " ";
	char* freq = " ";
	int count = 0;
	while((fgets(buff, 100, fp)) != NULL)
	{
		strtok(buff, " ");
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
	FILE *fp = fopen("encrypted.dat", "r");
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
	int i;
	for(i = 0; i < 26; i++)
	{
		found[i] = (found[i]/totalChars);
	}
	fclose(fp);
}

/*
** Moves to the next character in the alphabet
** 'num' places away. 
*/
char rotate(char ch, int num)
{
	if(num < 0)
		num = num + 26;
	
	if(isalpha(ch))
	{
		if(islower(ch))
			return (ch - 'a' + num) % 26 + 'a';
		if(isupper(ch))
			return (ch - 'A' + num) % 26 + 'A';
	}
	return ch;
}

/*
** Finding the key for decryption
*/
int findKey(float given[], float found[])
{
	int key = 0;
	float difference = 0;
	float least = INT_MAX;
	int i;
	for(i = 0; i < 26; i++)
	{
		int j;
		for(j = 0; j< 26; j++)
		{
			int index = (i+j) % 26;
			float temp = given[j] - found[index];
			if(temp < 0)
				temp = temp * -1;
			difference += temp;
		}
		//printf("The difference is: %f\n", difference);
		if(difference < least)
		{	
			least = difference;
			key = i;
		}
		difference = 0.0;
	}
	//printf("%d", key);
	return -key;
}

/*
** Decrypt the encoded data
*/
void decrypt(int key)
{
	FILE *fp = fopen("encrypted.dat", "r");
	FILE *out = fopen("final.dat", "w");
	char buff = ' ';
	while((buff = fgetc(fp)) != EOF)
	{
		if(isalpha(buff))
		{
			fprintf(out, "%c", rotate(buff, key));
		}
		else
		{
			fprintf(out, "%c", buff);
		}
	}
	fclose(fp);
	fclose(out);
}

/*
** Was getting garbage values when trying to
** update arrays in the middle, so I made this 
** function to initially set all float values to 0.
*/
void initArray (float found[])
{
	int i;
	for(i = 0; i < 26; i++)
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
	int i;
	for(i = 0; i < 26; i++)
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


