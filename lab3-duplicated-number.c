/*
Author: Takib Islam
Duplicated Number
*/

#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return arr[i]; // Return the duplicated number
            }
        }
    }
    return -1; // Return -1 if no duplicate is found
}

int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    //create array to store ints
    int size = argc - 1; //excluse file
    int arr[size];

    //convert command line args to ints
    for (int i = 1; i < argc; i ++)
    {
        arr[i-1] = atoi(argv[i]);
    }

    //Find the dupes
    int duplicate = findDuplicate(arr, size);

    //print
    if (duplicate != -1)
    {
        printf("%d\n", duplicate);
    }
    else
    {
        printf("no duplicated number\n");
    }

    return 0;
}