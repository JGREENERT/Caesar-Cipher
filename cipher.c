#include <stdio.h>

void readFreq(float given[])
{
	
	FILE *fp = fopen("LetFreq.txt", "r");
	char letter = ' ';
	while((letter = fgetc(fp)) != EOF)
	{
		given[letter]++;
	}			
	fclose(fp);
}

void calcFreq(float found[])
{


}

char rotate(char ch, int num)
{


}

int findKey(float given[], float found[])
{


}

void decrypt(int key)
{


}

void printTest(float toPrint[])
{
	for(int i = 0; i < sizeof(toPrint); i++)
	{
		char character = (char) (i);
		printf("%s %d: %f\n", "Character", character, toPrint[i]); 
	}
}

int main()
{
	float given[25];
	readFreq(given);	
	printTest(given);
}


