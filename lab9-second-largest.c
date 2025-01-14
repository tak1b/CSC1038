#include <stdio.h>
#include <stdlib.h>

float find_second_largest(float *arr, int size);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide at least two numbers.\n");
        return 1;
    }

    int size = argc - 1;
    float *arr = (float *)malloc(size * sizeof(float));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Parse input numbers
    for (int i = 0; i < size; i++) {
        arr[i] = atof(argv[i + 1]);
    }

    // Find and print the second largest element
    float second_largest = find_second_largest(arr, size);
    printf("%.1f\n", second_largest);

    free(arr);
    return 0;
}

float find_second_largest(float *arr, int size) {
    float largest = -__FLT_MAX__;
    float second_largest = -__FLT_MAX__;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }

    return second_largest;
}
