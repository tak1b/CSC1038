#include <stdio.h>

// Function to count the occurrences of a character in a string using pointers
int count_character(char *string, char target) {
    int count = 0;
    
    // Traverse the string using a pointer
    for (char *ptr = string; *ptr != '\0'; ptr++) {
        if (*ptr == target) {
            count++;
        }
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 3) {
        printf("Usage: %s <character> <string>\n", argv[0]);
        return 1;
    }

    // Get the character and string from the arguments
    char target = argv[1][0];  // The character to count
    char *string = argv[2];    // The string to search

    // Call the function to count occurrences
    int result = count_character(string, target);

    // Print the result
    printf("%d\n", result);

    return 0;
}
