/*
Author: 		Takib Islam
Number: 		23339236
Date:			31/10/2024
Module:			CSC1038
Exam:			Lab Exam 1
Question 2.1:	Inventory List
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define new type
typedef struct Item Item;

//define new struct
struct Item
{
	char name[20];
	int amount;
	float price;
	int promotion;
};

//prototypes
void addItems(Item it[], int argc, char*argv[]);
void printItems(Item it[], int numberOfItems);
void discount(int n);



int main(int argc, char*argv[])
{
	Item item[20];
	int numberOfItems = (argc - 1)/4; 
	addItems(item, argc, argv);
	printItems(item, numberOfItems);

	return 0;
}

//add items into an array and have a corresponding index to access later
void addItems(Item it[], int argc, char*argv[])
{
	int numberOfItems = (argc - 1)/4;

	int index = 1;
	for(int i = 0; i < numberOfItems; i++)
	{
		strcpy(it[i].name, argv[index]);
		it[i].amount = atoi(argv[index + 1]);
		it[i].price = atof(argv[index + 2]);
		it[i].promotion = atoi(argv[index + 3]);
		index = index + 4;
	}
}


//use a loop to go through each item and print it
void printItems(Item it[], int numberOfItems)
{
	for(int i = 0; i < numberOfItems; i++)
	{
		printf("%s,%i,%.2f", it[i].name, it[i].amount, it[i].price);
		discount(it[i].promotion);
	}
}


//used to check if the last input is 1 or 0
void discount(int n)
{
	if(n)
	{
		printf(",Discounted\n");
	}
	else
	{
		printf(",No Discount\n");
	}
}