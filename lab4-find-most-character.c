/*
Author: Takib Islam
Count Characters
*/

#include <stdio.h>
#include <stdlib.h>

char findMostFrequentChar(char* str);
void printMostFrequentChar(char c);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return 1;
    }

    // Find the most frequent character
    char mostFrequentChar = findMostFrequentChar(argv[1]);
    
    // Print the most frequent character
    printMostFrequentChar(mostFrequentChar);

    return 0;
}

char findMostFrequentChar(char* str) {
    int frequency[26] = {0}; // Array to store frequency for 'a' to 'z'

    // Iterate over the string and count the frequency of each character
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr >= 'a' && *ptr <= 'z') { // Only count lowercase letters
            frequency[*ptr - 'a']++; // Use the character to index the frequency array
        }
    }

    // Find the character with the maximum frequency
    char mostFrequentChar = '\0';
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mostFrequentChar = 'a' + i; // Map back to character
        }
    }

    return mostFrequentChar;
}

void printMostFrequentChar(char c) {
    printf("%c\n", c);
}

