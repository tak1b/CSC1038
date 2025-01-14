#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Function to find the second largest number in the array
float find_second_largest(float *arr, int n) {
    float largest = -FLT_MAX, second_largest = -FLT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);  // Get the number of elements

    float *arr = (float *)malloc(n * sizeof(float));  // Allocate memory dynamically
    for (int i = 0; i < n; i++) {
        arr[i] = atof(argv[i + 2]);  // Convert inputs to floats and store in array
    }

    // Find and print the second largest element, rounded to 1 decimal place
    printf("%.1f\n", find_second_largest(arr, n));

    free(arr);  // Free dynamically allocated memory
    return 0;
}
