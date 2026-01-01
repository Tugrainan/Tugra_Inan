#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// 1. Traversal: Printing the circular list
void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we come back to the start
    printf("(Head)\n");
}

// 2. Insertion: Adding a node after a specific node
void insertAfter(struct Node* prev_node, int data) {
    if (prev_node == NULL) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // Connect new node to the next one, then point prev to new node
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

// 3. Deletion: Removing a node by its value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;

    // Find the node to delete
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node not found.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If there is only one node in the list
    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    // If we are deleting the head node
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = (*head)->next;
        prev->next = *head;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

int main() {
    // Manually creating a simple circular list: 10 -> 20 -> (back to 10)
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = head;

    // Insert 15 between 10 and 20
    insertAfter(head, 15);

    printList(head); //
