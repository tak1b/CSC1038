#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("studentBinary.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Reading the length of the student name
    int nameLength;
    fread(&nameLength, sizeof(int), 1, file);

    // Reading the student name
    char *name = (char *)malloc(nameLength + 1);
    fread(name, sizeof(char), nameLength, file);
    name[nameLength] = '\0'; // Null-terminate the string

    // Reading the length of the college name
    int collegeLength;
    fread(&collegeLength, sizeof(int), 1, file);

    // Reading the college name
    char *college = (char *)malloc(collegeLength + 1);
    fread(college, sizeof(char), collegeLength, file);
    college[collegeLength] = '\0'; // Null-terminate the string

    // Reading the age
    int age;
    fread(&age, sizeof(int), 1, file);

    // Reading the grade
    float grade;
    fread(&grade, sizeof(float), 1, file);

    // Displaying the data
    printf("Name: %s\n", name);
    printf("College: %s\n", college);
    printf("Age: %d\n", age);
    printf("Grade: %.2f\n", grade);

    // Free allocated memory
    free(name);
    free(college);

    // Close the file
    fclose(file);

    return 0;
}
