#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char* ptr;
    int top;
    int max;
}CSTACK;

CSTACK* create_stack(int max)
{
    CSTACK* st;
    st = (CSTACK*)malloc(sizeof(CSTACK));
    st->max = max;
    st->top = -1;    
    st->ptr = (char*)malloc(st->max*sizeof(char));
    return st;
}

void liberate_stack(CSTACK* st)
{
    free(st->ptr);
    free(st);
}

bool check_overflow(CSTACK* st)
{
    return (st->top == (st->max)-1);
}

bool check_underflow(CSTACK* st)
{
    return (st->top == -1);
}

void push(CSTACK* st, char item)
{
    if(check_overflow(st))
    {
        printf("Stack is full.");
        exit(0);        
    }
    else
    {        
        st->ptr[++st->top] = item;
    }
}

char pop(CSTACK* st)
{
    if(check_underflow(st)) 
    {
        printf("Stack is empty.");
        exit(0);
    }               
    else
    {
        
        return st->ptr[st->top--];
    }
}

char peek(CSTACK* st)
{
    return st->ptr[st->top];
}

void disp_stack(CSTACK* st)
{
    for(int i = 0; i <= st->top; i++)
    {
        printf("%c ", st->ptr[i]);
    }    
}

int prec(char op)
{
    switch (op)
    {    
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool is_operand(char o)
{
    return isalnum(o);
}

bool is_operator(char op)
{
    return !isalnum(op);
}

char* infix_to_postfix(char* infix)
{

    //assignments and declarations
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    CSTACK* ops = create_stack(200);
    int postind = 0;

    for(int i = 0; *(infix+i)!='\0'; i++)
    {
        char cur = *(infix+i);
        if(is_operand(cur)) //alphanumerics directly added to postfix expression
        {
            postfix[postind++] = cur; 
        }
        else if(cur == '(') //opening brace pushed into stack
        {
            push(ops, cur);
        }
        else if(cur == ')') //all operators upto opening brace from encountering closing brace pushed into stack
        {
            while(!check_underflow(ops) && peek(ops)!='(')
            {
                postfix[postind++] = pop(ops);
            }     
            char g = pop(ops); //opening brace popped        
        }    
        else
        {
            while(!check_underflow(ops) && prec(cur) <= prec(peek(ops))) //popping higher priority operators after comparing with current operator in infix
            {
                postfix[postind++] = pop(ops);
            }
            push(ops, cur); //pushing current operator after popping higher priority operators
        }    
    }
    while(!check_underflow(ops))
    {
        postfix[postind++] = pop(ops); //popping remaining operators into postfix expression
    }
    postfix[postind] = '\0';
    liberate_stack(ops);
    
    return postfix;
    free(postfix);
}



int main(void)
{
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%[^\n]", infix);
    printf("The postfix expression is: %s\n", infix_to_postfix(infix));
}

/*Output:
Enter the infix expression: (a+b)^c/d-e*f
The postfix expression is: ab+c^d/ef*-
*/