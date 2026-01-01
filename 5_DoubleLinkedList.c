//adding element to finish point on double linked lists
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    newNode->data = new_data;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        newNode->prev = NULL;
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL) last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

//deleting all array elements recursively

void deleteListRecursive(struct Node* head) {
    if (head == NULL) return;
    deleteListRecursive(head->next);
    printf("Deleting node with data: %d\n", head->data);
    free(head);
}


//adding element to spesific index on double linked lists

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = new_data;

    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
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
