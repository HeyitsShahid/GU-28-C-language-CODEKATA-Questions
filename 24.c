//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to print the list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Step 1: Reverse the linked list
void reverseList(Node** head_ref) {
    Node *temp = NULL;
    Node *current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

// Step 2: Remove duplicates from the linked list
void removeDuplicates(Node** head_ref) {
    Node* current = *head_ref;
    Node* next;
    int hash[1000001] = {0};

    while (current != NULL) {
        if (hash[current->data] == 1) {
            next = current->next;

            if (current->prev != NULL)
                current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            free(current);
            current = next;
        } else {
            hash[current->data] = 1;
            current = current->next;
        }
    }
}

// Step 3: Insert the sum of all elements at the end of the list
void insertSumAtEnd(Node** head_ref) {
    Node* current = *head_ref;
    int sum = 0;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    append(head_ref, sum);
}

// Main function to perform all operations
void transformArray(Node** head_ref) {
    // Step 1: Reverse the list
    reverseList(head_ref);

    // Step 2: Remove duplicates
    removeDuplicates(head_ref);

    // Step 3: Insert sum at the end
    insertSumAtEnd(head_ref);
}

int main() {
    int n, data;
    Node* head = NULL;

    // Input number of elements
    scanf("%d", &n);

    // Input linked list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    // Perform the transformation
    transformArray(&head);

    // Output the final list
    printList(head);

    return 0;
}
