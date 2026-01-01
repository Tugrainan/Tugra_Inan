#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tok[16];           // "=", "+", "*", "a", "b", "c", "2"...
    struct Node *L, *R;     // left / right
} Node;

Node* leaf(const char* t){ Node* n=malloc(sizeof *n); strcpy(n->tok,t); n->L=n->R=NULL; return n; }
Node* bin (const char* t, Node* L, Node* R){ Node* n=leaf(t); n->L=L; n->R=R; return n; }


void print_tree_like_sample(Node* n, int depth){
    if(!n) return;
    
    for(int i=0;i<depth;i++) printf("  ");
    printf("%s\n", n->tok);

    if(n->L || n->R){
        for(int i=0;i<depth;i++) printf("  ");
        printf("/ \\\n"); 
        
        if(n->L){
            for(int i=0;i<depth;i++) printf("  ");
            print_tree_like_sample(n->L, depth+1);
        }
       
        if(n->R){
            for(int i=0;i<depth;i++) printf("  ");
            print_tree_like_sample(n->R, depth+1);
        }
    }
}


void print_sideways(Node* n, int indent){
    if(!n) return;
    print_sideways(n->R, indent+4);
    for(int i=0;i<indent;i++) putchar(' ');
    printf("%s\n", n->tok);
    print_sideways(n->L, indent+4);
}

int main(void){
    // a = b + c * 2  →  "=" kök; sağ taraf +; çarpım sağ dalda
    Node* ast =
        bin("=",
            leaf("a"),
            bin("+",
                leaf("b"),
                bin("*",
                    leaf("c"),
                    leaf("2"))));

    
    print_tree_like_sample(ast, 0);

    puts("\n--- sideways view (optional) ---");
    print_sideways(ast, 0);

    return 0;
}
