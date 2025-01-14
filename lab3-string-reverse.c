/*
Author: Takib Islam
Reverse a String
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]) {
    
    // Get the input string
    char str[51]; // Maximum character limit is 50, so 51 with null terminator
    strncpy(str, argv[1], 50); // Copy only up to 50 characters
    str[50] = '\0'; // Ensure null termination

    int len = strlen(str);

    // Print the string in reverse order
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
