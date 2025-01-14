/*
 circle-area-further.c
 author Takib Islam
*/


#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main(int argc, char* argv[]) {
    double radius, area;

    // Get radius input from the command-line argument
    if (argc != 2) {
        printf("Please provide a radius as a command-line argument.\n");
        return 1;
    }

    // Convert the command-line argument to a double
    radius = atof(argv[1]);

    // Option 1: Handle negative radius automatically
    if (radius < 0) {
        printf("Radius cannot be negative. Converting to positive.\n");
        radius = -radius;
    }

    // Option 2: Alert the user and let them try again
    // if (radius < 0) {
    //     printf("Error: Radius cannot be negative. Please enter a valid radius.\n");
    //     return 1;
    // }

    // Calculate the area of the circle
    area = PI * radius * radius;

    // Display the result
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);

    return 0;
}
