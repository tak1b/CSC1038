/*
 convert-units.c
 author Takib Islam
 */

#include <stdio.h>
#include <stdlib.h>
#define inch 2.54

int main(int argc, char*argv[])
{
    //initialise variables
    float cm = 0.0;
    float output = 0.0;
    cm = atoi(argv[1]);
    output = cm / inch;
    printf("%.2f\n",output);
    return(0);
}
