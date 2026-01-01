#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* node(int v, Node* L, Node* R){
    Node* n = (Node*)malloc(sizeof(Node));
    n->val=v; n->left=L; n->right=R; return n;
}

void preorder(Node* r){
    if(!r) return;
    printf("%d ", r->val);   // Root
    preorder(r->left);       // Left
    preorder(r->right);      // Right
}

int main(void){
    // resmi kur: 1,2,3,4,5,6,7
    Node* t4 = node(4, NULL, NULL);
    Node* t5 = node(5, NULL, NULL);
    Node* t6 = node(6, NULL, NULL);
    Node* t7 = node(7, NULL, NULL);
    Node* t2 = node(2, t4, t5);
    Node* t3 = node(3, t6, t7);
    Node* t1 = node(1, t2, t3);

    preorder(t1);
    return 0;
}
