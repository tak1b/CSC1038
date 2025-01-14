/*
  This program accepts an integer n followed by n floating-point numbers as command-line arguments.
  It stores the numbers in a doubly linked list using dynamic memory allocation.
  The numbers are then displayed in reverse order, one per line with two decimal places.
  Author: Takib Islam
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    float value;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node* createNode(float value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node to the list
void appendNode(struct Node **head, struct Node **tail, float value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Function to print the list in reversed order
void printReversedList(struct Node *tail) {
    struct Node *temp = tail;
    while (temp != NULL) {
        printf("%.2f\n", temp->value);
        temp = temp->prev;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s n num1 num2 ... numN\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (argc != n + 2) {
        printf("Error: Expected %d floating-point numbers after n.\n", n);
        return 1;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    // Read numbers from command-line arguments and append to the list
    for (int i = 2; i < argc; i++) {
        float value = atof(argv[i]);
        appendNode(&head, &tail, value);
    }

    // Print the list in reversed order
    printReversedList(tail);

    // Free allocated memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
