#include <stdio.h>
#include <stdlib.h>

/*
  Author: Takib Islam
  The program dynamically creates a linked list from a predefined list of integers,
  searches for the target value, inserts the new value after the target, and finally
  displays the updated linked list line by line.
 */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a value after a specified target value
void insertAfter(Node* head, int target, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            Node* newNode = createNode(value);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Target value %d not found in the list.\n", target);
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to free the linked list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function
int main(int argc, char* argv[]) {
    // List of unique numbers
    int numbers[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Validate command-line arguments
    if (argc != 3) {
        printf("Usage: %s <target> <value>\n", argv[0]);
        return 1;
    }

    int target = atoi(argv[1]);
    int value = atoi(argv[2]);

    // Create the linked list from the array
    Node* head = createNode(numbers[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(numbers[i]);
        current = current->next;
    }

    // Insert the new value after the target value
    insertAfter(head, target, value);

    // Print the updated linked list
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
