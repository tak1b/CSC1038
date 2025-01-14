/*
Description: This program uses realloc to reallocate more space if there are more than 2 students and prints out all students at the end.
Author: Takib Islam
Date: 12/11/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students Students;

// Student structure 
struct Students {
    char name[20];
    char programme[20];
    float grade;
};

// protoypes
void populating(Students *student, int amount_students, char *argv[]);
void display(Students *student, int amount_students);

int main(int argc, char *argv[]) {
    // amount of students
    int amount_students = (argc - 1) / 3;
    int size = 2;

    // memeory allocation
    Students *student = (Students*)malloc(size * sizeof(Students));
    if (student == NULL) {
        printf("Not enough memory!\n");
    }

    // memeory allocation
    if (amount_students > size) {
        size = amount_students;
        Students *temp = (Students*)realloc(student, size * sizeof(Students)); // Temporary name is used to reallocate the space needed
        if (temp == NULL) { // Prints this if there is not enough memory to allocate the space needed
            printf("Not enough memory!\n");
        } else {
            student = temp;
        }
    }

    // calls function
    populating(student, amount_students, argv);
    display(student, amount_students);

    free(student); // Frees the previously allocated space of student

    return 0;
}

void populating(Students *student, int amount_students, char *argv[]) {
    for (int i = 0; i < amount_students; i++) {
        strcpy(student[i].name, argv[i * 3 + 1]); 
        strcpy(student[i].programme, argv[i * 3 + 2]);
        student[i].grade = atof(argv[i * 3 + 3]); 
    }
}

void display(Students *student, int amount_students) {
    // prints
    for (int i = 0; i < amount_students; i++) {
        printf("%s, %s, %.2f\n", student[i].name, student[i].programme, student[i].grade);
    }
}
