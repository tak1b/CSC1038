/*
Author: Takib Islam (23339236)
Description: This programme displays how frequently a number appears
Date: 28/11/24
*/

// Includes
#include <stdio.h>
#include <stdlib.h> // Required for memory allocation commands. malloc(), free()

// Struct Definition
typedef struct num num;

struct num {
    int val;
    num* next; 
    num* prev;
};

// Function Prototypes
num* constructList(int size, char**argv);
int countNum(int n, num* listHead);
int findDegree(num* listHead);
void freeList(num* listHead);

int main(int argc, char**argv) {
    // Initialize variables
    int size;
    num* head;

    // Get size and construct linked list using constructList()
    size = argc - 1;  //-1 to insure not to count the filename in the argument count
    head = constructList(size, argv);

    // Find the degree of the linked list using findDegree() and output
    printf("%d\n", findDegree(head));

    // Free all memory associated with the linked list
    freeList(head);
    head = NULL;

    return 0; // End program
}

// Creates a linked list using the nums from argv by using dynamic allocation on each struct and then linking
num* constructList(int size, char**argv) {
    num* head;  //head pointer to go to the head of the linked list
    num* curr;  //pointer to be at the current location of the list
    num* tmp;   //temporary pointer used to assign values that may be discarded soon

    // Create head node
    head = (num*) malloc(sizeof(num));  //memeory allocation failsafe
    if (!head) {
        printf("Memory allocation failed.");
        exit -1;
    }
    
    head->val = atoi(argv[1]); //pointer to start at the given list. starting at argv[1] because argv[0] is the filename(./ex2-array-degree.c) and not an actual value
    head->next = NULL; //empty because it is not yet assigned a value
    head->prev = NULL; //empty as it is not yet assigned a value

    // Allocate, create, and link the rest of the list
    curr = head;
    for (int i = 1; i < size; i++) {
        tmp = (num*) malloc(sizeof(num));
        if (!tmp) {
            printf("Additional allocation failed.\n");
            free(head);
            head = NULL;
            exit -2;
        }

        tmp->val = atoi(argv[i + 1]);
        tmp->next = NULL;
        tmp->prev = curr;

        curr->next = tmp;
        curr = tmp;
    }

    // Discard unneccessary pointers
    curr = NULL;
    tmp = NULL;

    return head;
}

// Counts how many times n occurs in a given linked list, then returns the count
int countNum(int n, num* listHead) {
    int count = 0; //initialise count which will be the output

    while (listHead) {
        if (listHead->val == n) {
            count++;
        }

        listHead = listHead->next;
    }

    return count;
}

// Check how many times each item in the list occurs using countNum(), then returns the highest degree
int findDegree(num* listHead) {
    int tmp;
    int degree = 0;

    while (listHead) {
        tmp = countNum(listHead->val, listHead);
        if (tmp > degree) { //used to compare current and previous values. if the tmp is the highest occuring value degree will then be the value returned
            degree = tmp;
        }

        listHead = listHead->next;
    }

    return degree;
}

// Using 2 pointers, free 1 node before moving onto the next until the end of the list is reached
void freeList(num* listHead) {
    num* prev;

    while (listHead) {
        prev = listHead;
        listHead = listHead->next;

        free(prev);
    }

    prev = NULL;
}