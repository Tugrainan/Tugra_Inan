
#include <stdio.h>
#include <ctype.h>

int prec(char op){ if(op=='^') return 3; if(op=='*'||op=='/') return 2; if(op=='+'||op=='-') return 1; return 0; }
int right_assoc(char op){ return op=='^'; }

int main(void){
    char s[256]; if(!fgets(s,sizeof s,stdin)) return 0;
    char st[256]; int top=-1;
    for(char *p=s; *p; ++p){
        if(isspace(*p)) continue;
        if(isalnum(*p)) { putchar(*p); continue; }
        if(*p=='(') { st[++top]='('; continue; }
        if(*p==')'){ while(top>=0 && st[top]!='(') putchar(st[top--]); if(top>=0) top--; continue; }
        // operator
        while(top>=0 && st[top]!='(' &&
              (prec(st[top])>prec(*p) || (prec(st[top])==prec(*p) && !right_assoc(*p))))
            putchar(st[top--]);
        st[++top]=*p;
    }
    while(top>=0) putchar(st[top--]);
    putchar('\n');
}
/*The Shunting Yard Algorithm is used to convert expressions from infix 
(like $a + b$) to postfix (like $ab+$). It uses a Stack to store operators 
and follows specific rules based on operator precedence. For example,
 multiplication ($*$) is processed before addition ($+$). When we see an 
operand (a letter or number), we move it directly to the output. 

If we see an operator, we check the stack; if the operator in the stack 
has higher priority, we pop it to the output first. Parentheses are special;
 we push the opening bracket to the stack and pop everything inside 
it when we find the closing bracket. This method ensures the computer can
calculate mathematical expressions easily without needing parentheses.*/