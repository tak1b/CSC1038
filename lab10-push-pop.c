/*
  Program: Push and Pop in a Linked List
  This program accepts an integer n, followed by n integers, and then a new integer to be pushed to the list.
  It performs the following operations:
  1. Pop the last two elements from the list.
  2. Push the last two input integers into the list.
  3. Display all the elements of the updated list line by line.
  The program uses a linked list and dynamic memory allocation.
  Author: Takib Islam
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
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

// Function to append a node to the end of the list
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

// Function to remove the last node (pop)
void popNode(struct Node **head) {
    if (*head == NULL) return;

    struct Node *temp = *head;
    if (temp->next == NULL) { // If there's only one node
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
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
    if (argc < 4) {
        printf("Usage: %s n num1 num2 ... numN newNum1 newNum2\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (argc != n + 4) {
        printf("Error: Expected %d integers followed by 2 new integers.\n", n);
        return 1;
    }

    struct Node *head = NULL;

    // Create the initial list from the input arguments
    for (int i = 2; i <= n + 1; i++) {
        int value = atoi(argv[i]);
        appendNode(&head, value);
    }

    // Pop the last two elements from the list
    popNode(&head);
    popNode(&head);

    // Push the new integers into the list
    int newNum1 = atoi(argv[n + 2]);
    int newNum2 = atoi(argv[n + 3]);
    appendNode(&head, newNum1);
    appendNode(&head, newNum2);

    // Print the updated list
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
