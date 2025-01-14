/*
Author: Takib Islam (23339236)
Question: Student Attendance Record
Description: This programme will check to see if a student is coming into class and output a value depending on the attendance record given
*/

// Includes
#include <stdio.h>
#include <stdlib.h> // Required of malloc(), free()
#include <string.h> // Required for strlen(), strcpy()

// Function Prototypes
char** constructArray(int capacity, char**argv);
int attendanceCheck(char* attendance);
void printStudents(char** studentList, int capacity);
void freeList(char** studentList, int capacity);

int main(int argc, char** argv) {
    // Initialize Variables
    int size;
    char** students;

    // Get size and construct the list of attendances using constructArray()
    size = argc - 1;
    students = constructArray(size, argv);

    // Print out the attendace status of each student using printStudents()
    printStudents(students, size);

    // Free all memory associated with thte array
    freeList(students, size);
    students = NULL;

    return 0; // End program
}

// Allocates enough memory to hold enough string pointers and the subsequent strings, stores command line args into the newly created array and returns a pointer to it after
char** constructArray(int capacity, char**argv)
{
    char** students;

    // Allocate memory to hold pointers
    students = (char**) malloc(sizeof(char*) * capacity);
    if (!students) 
    {
        printf("Memory Allocation failed.");
        exit -1;
    }

    // Allocate additional memory for each string and populate array
    for (int i = 0; i < capacity; i++) 
    {
        students[i] = (char*) malloc(sizeof(char) * (strlen(argv[i + 1]) + 1)); // +1 to include NULL terminator
        if (!students[i]) 
        {
            printf("Additional Allocation failed.");
            free(students);
            students = NULL;
            exit -2;
        }

        strcpy(students[i], argv[i + 1]);
    }

    return students;
}

// Keeps counters  A and L, then returns 0 or 1 based on if A >= 
int attendanceCheck(char* attendance) 
{
    // Initialize counters
    int a  = 0;
    int l = 0;

    for (int i = 0; i < strlen(attendance); i++) 
    {
        if (attendance[i] == 'L' && attendance[i+1] == 'L' && attendance[i+2] == 'L' && attendance[i + 3] == 'L') 
        {
            a++;

            if (l == 4) 
            {
                a++;
                l = 1;
            }
        }
        else 
        {
            if (attendance[i] == 'A') 
            {
                a++;
            }

            l = 0;
        }
    }

    if (a >= 4) 
    {
        return 1;
    }
    return 0;
}

// Goes through the student list and prints the return value of attendanceCheck()
void printStudents(char** studentList, int capacity) 
{
    for (int i = 0; i < capacity; i++) 
    {
        printf("%d\n", attendanceCheck(studentList[i]));
    }
}

// Iterates through the list, freeing string stored at each location, then frees the outer list
void freeList(char** studentList, int capacity) 
{
    for (int i = 0; i < capacity; i++)
     {
        free(studentList[i]);
    }
    
    free(studentList);
}