/*
** Author: Jesse Greenert
*/

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

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
		//printf("%s: %s\n", index, freq);
		given[count] = atof(freq);
		count++;
	}
			
	fclose(fp);
}

void calcFreq(float found[])
{
		
}

char rotate(char ch, int num)
{

	return 0;
}

int findKey(float given[], float found[])
{

	return 0;
}

void decrypt(int key)
{


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
}

/*
** Main Method
*/
int main()
{
	float given[26];
	float found[26];
	readFreq(given); //Reading in known frequencies	
	printTest(given); //Printing out Given
	calcFreq(found); //Finding character frequencies of file
	printTest(found); //Pritning out Found
}


