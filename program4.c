#include "stackfuncs.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

int prec(char ops)
{
    switch (ops)
    {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;    
        default: return 0;
    }
}

bool is_operand(char ops)
{
    return isalnum(ops);
}

bool is_operator(char ops)
{
    return !isalnum(ops);
}

char* infix_to_postfix(char* infix)
{
    STACK* ops = create(10);
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int postind = 0;
    for(int i=0;*(infix+i)!='\0';i++)
    {
        char cur = infix[i];
        if (is_operand(cur))        
        {
            postfix[postind++] = cur;
        }
        else if(cur=='(')
        {
            push(ops, cur);
        }
        else if(cur==')')
        {
            while(!check_underflow(ops) && peek(ops)!='(')
            {
                postfix[postind++] = pop(ops);
            }
            char garbage = pop(ops);
        }
        else if(is_operator(cur))
        {
            while((!check_underflow(ops)) && (prec(cur)<=prec(peek(ops)) && (peek(ops)!='(')))
            {
                postfix[postind++] = pop(ops);
            }
            push(ops, cur);
        }
    }

    while(!check_underflow(ops))
    {
        postfix[postind++] = pop(ops);
    }
    postfix[postind] = '\0';
    liberate(ops);
    return postfix;
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char* postfix = infix_to_postfix(infix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    free(postfix);
    return 0;
}

/*Output:
Enter an infix expression: (a+b)*c-d/e
Infix Expression: (a+b)*c-d/e
Postfix Expression: ab+c*de/-
*/
