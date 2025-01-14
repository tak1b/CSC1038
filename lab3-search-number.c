/*
Author: Takib Islam
Search Number
*/

#include <stdio.h>
#include <stdlib.h>

// Function to search for a number in the array
int searchNumber(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <number-to-search> <list of integers>\n", argv[0]);
        return 1;
    }

    // Convert the first argument to the target number
    int target = atoi(argv[1]);

    // Create an array to store the integers
    int size = argc - 2; // Exclude the program name and the target number
    int arr[size];

    // Convert the command-line arguments to integers and store them in the array
    for (int i = 2; i < argc; i++) {
        arr[i - 2] = atoi(argv[i]);
    }

    // Search for the number
    int index = searchNumber(arr, size, target);

    // Print the result
    if (index != -1) {
        printf("Found %d at %d\n", target, index);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}
