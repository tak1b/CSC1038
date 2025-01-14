/*
 rugby.c
 author Takib Islam
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    //initalise variables
    int output = 0;
    int try = 5 * atoi(argv[1]);
    int conversion = 2 * atoi(argv[2]);
    int penalty = 3 * atoi(argv[3]);
    int drop = 3 * atoi(argv[4]);

    output = try + conversion + penalty + drop;

    
    printf("%d\n", output);

    return 0;

}