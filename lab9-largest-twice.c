/*
Description: This program takes in a list of integers and if there is a number which is twice as big as another number
inside of the array, it will then find it and print it; otherwise, it will print 0.
Author: Takib Islam
Date: 12/11/24
*/

#include <stdio.h>
#include <stdlib.h>

// rotoypes
void populating(int *pnumbers, int size, char *argv[]);
int largest(int *pnumbers, int size);

int main(int argc, char *argv[]) {
   
    int size = argc - 1;

    int *pnumbers = (int*)malloc(size * sizeof(int));

    if (pnumbers == NULL) {
        printf("Failed to allocate memory!\n");
    }

    populating(pnumbers, size, argv);
    int result = largest(pnumbers, size); 

    free(pnumbers); 

    printf("%d\n", result); 

    return 0;
}

// Populates the pnumbers array with the command line integers given
void populating(int *pnumbers, int size, char *argv[]) {
    for (int i = 0; i < size; i++) {
        pnumbers[i] = atoi(argv[i + 1]);
    }
}

// use pointer of numbers array and size of that array
int largest(int *pnumbers, int size) {
    // initialise vars
    int largest = 0;

    // Loops through each variable and whichever is bigger than the current largest is overwritten as that number
    for (int i = 0; i < size; i++) {
        if (largest < pnumbers[i]) {
            largest = pnumbers[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (largest >= 2 * pnumbers[i]) {
            return largest; // If it finds at least one number which is half the size or less, returns the largest number
        }
    }

    return 0; // If there is no number that is half the size of the largest number or less, return 0 as instructed
}
