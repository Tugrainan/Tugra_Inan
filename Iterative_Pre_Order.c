#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int val; struct Node *left,*right; } Node;
Node* node(int v, Node* L, Node* R){ Node* n=malloc(sizeof* n); n->val=v; n->left=L; n->right=R; return n; }

typedef struct { Node* a[64]; int top; } Stack;
void spush(Stack* s, Node* x){ s->a[++s->top]=x; }
Node* spop(Stack* s){ return s->a[s->top--]; }
int sempty(Stack* s){ return s->top<0; }

void preorder_iter(Node* r){
    if(!r) return;
    Stack s = {.top=-1};
    spush(&s, r);
    while(!sempty(&s)){
        Node* cur = spop(&s);
        printf("%d ", cur->val);     // root
        if(cur->right) spush(&s, cur->right); // dikkat: önce right push
        if(cur->left)  spush(&s, cur->left);  // sonra left push → left önce çıkar
    }
}

int main(void){
    Node* t4=node(4,NULL,NULL), *t5=node(5,NULL,NULL);
    Node* t6=node(6,NULL,NULL), *t7=node(7,NULL,NULL);
    Node* t2=node(2,t4,t5),     *t3=node(3,t6,t7);
    Node* t1=node(1,t2,t3);

    preorder_iter(t1);
    return 0;
}
