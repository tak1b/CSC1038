/*
Author: Takib Islam
Simple Calculator
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to multiply two numbers
float multiply(float a, float b) {
    return a * b;
}

// Function to divide two numbers
float divide(float a, float b) {
    if (b == 0) {
        return -1; // Return an invalid result if division by zero
    }
    return a / b;
}

// Function to handle the operation based on input
void calculate(char *operation, float num1, float num2) {
    if (strcmp(operation, "multiply") == 0) {
        printf("%.6f\n", multiply(num1, num2));
    } 
    else if (strcmp(operation, "divide") == 0) {
        float result = divide(num1, num2);
        if (result == -1) {
            printf("invalid\n");
        } else {
            printf("%.6f\n", result);
        }
    } 
    else {
        printf("invalid\n");
    }
}

int main(int argc, char *argv[]) {
    // Ensure that the correct number of arguments are provided
    if (argc != 4) {
        printf("invalid\n");
        return 1;
    }

    // Parse the operator and the two floating-point numbers
    char *operation = argv[1];
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);

    // Perform the calculation
    calculate(operation, num1, num2);

    return 0;
}
