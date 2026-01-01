//adding element to finish point on double linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void insertEnd(Node **head_ref, int new_data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { perror("malloc"); exit(1); }

    newNode->data = new_data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head_ref == NULL) {          // boþ liste
        *head_ref = newNode;
        return;
    }

    Node *last = *head_ref;
    while (last->next != NULL) last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

// prev_node: ekleme yapýlacak düðüm (prev_node'dan SONRA ekler)
void insertAfter(Node *prev_node, int new_data) {
    if (prev_node == NULL) return;

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { perror("malloc"); exit(1); }

    newNode->data = new_data;

    newNode->next = prev_node->next;
    newNode->prev = prev_node;

    if (prev_node->next != NULL)
        prev_node->next->prev = newNode;

    prev_node->next = newNode;
}

void printList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// head'i de NULL yapmak için Node** kullanýyoruz
void deleteListRecursive(Node **head_ref) {
    if (*head_ref == NULL) return;

    deleteListRecursive(&(*head_ref)->next);
    free(*head_ref);
    *head_ref = NULL;
}

int main() {
    Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printList(head); // 10 <-> 20 <-> 30 <-> NULL

    // 20'nin sonrasýna 99 ekle
    insertAfter(head->next, 99);
    printList(head); // 10 <-> 20 <-> 99 <-> 30 <-> NULL

    deleteListRecursive(&head);
    printList(head); // NULL

    return 0;
}


/*
The main difference is that a Circular Linked List connects the last node
back to the first one instead of pointing to NULL. This creates a continuous
loop, which is very useful for tasks like round-robin scheduling, but it
makes sorting a bit more difficult. When using algorithms like Bubble Sort,
 we must be very careful with our loop conditions; if we don't track the
starting point correctly, the program will stay in an infinite loop.
Therefore, while circular lists offer great flexibility for repetitive tasks,
 they require more attention during implementation compared to normal linked
lists
*/
