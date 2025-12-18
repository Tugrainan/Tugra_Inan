//this hw for showing linked list processes

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// 1. Traversal: Print the list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

// 2. Insertion: begginning of the list
void insertFront(struct Node** head_ref, int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

// 3. Insertion: End of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    newNode->data = new_data;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) last = last->next;
    last->next = newNode;
}

// 4. Deletion: Delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 12);
    insertFront(&head, 7);
    insertEnd(&head, 38);

    printf("Linked List: ");
    printList(head);

    deleteNode(&head, 12);
    printf("After Deleting 12: ");
    printList(head);

    return 0;
}