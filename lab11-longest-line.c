#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200 // Maximum length of each sentence
#define FILE_NAME "paragraph.txt"

int main() {
    FILE *file;
    char sentence[MAX_LENGTH];    // Buffer to store each line
    char longest_sentence[MAX_LENGTH] = ""; // Buffer to store the longest sentence
    int longest_length = 0;       // Length of the longest sentence

    // Open the file for reading
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", FILE_NAME);
        return 1;
    }

    // Read each line (sentence) from the file
    while (fgets(sentence, MAX_LENGTH, file) != NULL) {
        int length = strlen(sentence);

        // Remove trailing newline character if present
        if (sentence[length - 1] == '\n') {
            sentence[length - 1] = '\0';
            length--;
        }

        // Check if this sentence is the longest
        if (length > longest_length) {
            longest_length = length;
            strcpy(longest_sentence, sentence);
        }
    }

    // Close the file
    fclose(file);

    // Display the length of the longest sentence and the sentence itself
    printf("%d\n", longest_length + 1);
    printf("%s\n\n", longest_sentence);

    return 0;
}
