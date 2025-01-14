#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char*argv[])
{
    //arg checks
    if (argc == 1) {
        printf("No input given!\n");
        return 0;
    }
    
    else if (argc == 2) {
        printf("Two arguments needed!\n");
        return 0;
    }

    //convert args to nums
    float radius = atof(argv[1]);
    float height = atof(argv[2]);

    //check is inputs are negative
    if (radius < 0 || height < 0) {
        printf("The radius or height cant be neative!\n");
        return 0;
    }

    /*
    Calculate the area of the cylinder
    Formula: A=2πrh+2πr^2
    */
    float area = (2 * PI * radius * height) + (2 * PI * radius * radius);

    //output
    printf("%.2f\n", area);
    return 0;

}


