/*
This program accepts an integer n followed by n integers as command-line arguments.
It stores the integers in a singly linked list using dynamic memory allocation.
The integers are then displayed one by one on separate lines.
Author: Takib Islam
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int value;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the list
void appendNode(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the list
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
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
        printf("Error: Expected %d numbers after n.\n", n);
        return 1;
    }

    struct Node *head = NULL;

    // Read numbers from command-line arguments and append to the list
    for (int i = 2; i < argc; i++) {
        int value = atoi(argv[i]);
        appendNode(&head, value);
    }

    // Print the list
    printList(head);

    // Free allocated memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
