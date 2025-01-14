/*
Author: Takib Islam
Find Max number
*/

#include <stdio.h>
#include <stdlib.h>

int findmax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}


int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    //create an array to sotre integers
    int size = argc - 1;
    int arr[size];

    //conert command line integers and sotre them in an array
    for (int i = 1; i < argc; i ++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    //find max
    int max = findmax(arr, size);

    //print
    printf("%d\n", max);
    
    return 0;
}