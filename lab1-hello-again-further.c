/*
 hello-again-further.c
 author Takib Islam
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    char name[50];  //set variable to take a random number of letters (I did 50 cuz no way input bigger than 50)
    printf("enter your name: ");    //asking for user name
    scanf("%s", name);              // takes entered user name

    printf("Hello %s\n", name);     //produces output

}