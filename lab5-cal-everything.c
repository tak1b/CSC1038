/*
Author: Takib Islam
Calculate everything
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double sum(int, int);
double difference(int, int);
double product(int, int);
double division(int, int);
double power(int, int);
double logarithm(int, int);
double all_functions(double (*pfun)(int, int), int a, int b);

int main(int argc, char *argv[]) {
    // Initializes the 2 numbers to be used, as well as the result starting at 0.0 because it is a double
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    double result = 0.0;

    // Pointer to the function
    double (*pf)(int, int) = NULL;

    // This prints all of the results for each type
    pf = sum;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    pf = difference;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    pf = product;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    pf = division;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    pf = power;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    pf = logarithm;
    result = all_functions(pf, a, b);
    printf("%.2f\n", result);

    return 0;
}

// Function that calls the given function with a and b
double all_functions(double (*pfun)(int, int), int a, int b) {
    return pfun(a, b);
}

// Calculation functions
double sum(int a, int b) {
    return a + b;
}

double difference(int a, int b) {
    return a - b;
}

double product(int a, int b) {
    return a * b;
}

double division(int a, int b) {
    return (double)a / b;
}

double power(int a, int b) {
    return pow(a, b);
}

double logarithm(int a, int b) {
    return log(a) + log(b);
}
