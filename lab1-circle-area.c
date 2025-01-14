/*
circle-area.c
author Takib Islam
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char*argv[])
{
    // variable initialisation
    int radius = 0;
    float area = 0.0;

    /*all cml args come in as char string so atoi turns into ints*/

    radius = atoi(argv[1]);

    radius = radius*radius;
    area = radius*PI;

    printf("%.2f\n",area);
    //printf("%9.2f\n", area);
    return 0;
}