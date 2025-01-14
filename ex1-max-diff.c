/*
Author: 	Takib Islam
Number: 	23339236
Date:		31/10/2024
Module:		CSC1038
Exam:		Lab Exam 1
Question 1:	Maximum Difference Finder
Purpose:	The purpouse of this programme is to take in an array of numbers between 2 - 100, find the largest and smallest and returning the difference
Method:		The method used here is a simple sorting algorithm that will compare 2 numbers at a time and organise in a way that is necessary to complete the task.
			In this case it will first sort itself until it finds the biggest number then sort itself until it finds the largest number.
*/


#include <stdio.h>
#include <stdlib.h>  //used for atoi

int find_max_difference(int arr[], int size)
{

	//find max by comparing previous number to current number. once it finds the biggest number it saves it then loops to find the smallest. Once it finds the biggest it
	//looks for the smallest. once that is found it will return the difference of the both of them

	int max = arr[0];
	int min = arr[0];

	for(int i = 1; i < size; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return max-min;
}

int main(int argc, char* argv[])
{
	int n = argc - 1; //number of arguments excluding null terminator


	//make sure it only accepts up to 100 integers
	if(n > 100)
	{
		return 1;   
	}

	//put the integer into the array
	//loop through the array and convert the argument into an integer
	int arr[n];  
	for (int i = 0; i < n; i++)
	{
		arr[i] = atoi(argv[i + 1]); 
	}

	//call upon the previous function and provide it the 2 arguments it needs
	int max_diff = find_max_difference(arr, n);
	printf("%d\n", max_diff); //print the expected output

	return 0;

}