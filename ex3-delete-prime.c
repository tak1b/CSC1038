/*
Author: Takib Islam (23339236)
Question: Student Attendance Record
Description: This programme will iterate through and look for a prime number. Once it finds a prime number it will remove the prime number. With the
remaining numbers, it will find the average by adding them all and then dividing by how many numbers are left.
*/

#include<stdio.h>
#include<stdlib.h>

int findNonePrimes(int numbers[], int length);

int main(int argc, char *argv[])
{
	int length = argc - 1;   
	int numbers[50];
	int found;

	for(int i = 0; i < length; ++i)
	{
		numbers[i] = atoi(argv[i+1]);
	}

	found = findNonePrimes(numbers, length);
	if(found == -1)
	{
		printf("no non prime number\n");
	}
	else
	{
		printf("%d\n", found);
	}

	return 0;
}


//iterate through each of the numbers in the element and append to numbers[]
int findNonePrimes(int numbers[], int length)
{
	for(int i = 0; i < length; i++)
	{
		if (numbers[i] % 2 == 0 && numbers[i] != 2)
		{
			return numbers[i];
		}

	}
	return 0;
}

//unable to figure out why it only appends the first number seen