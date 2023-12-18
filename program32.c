#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

typedef struct {
    char* ptr;
    int top;
    int max_size;
} STACK;

STACK* create(int max_size)
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->max_size = max_size;
    stack->top = -1;
    stack->ptr = (char*)malloc(stack->max_size*sizeof(char));
    return stack;
}
 
bool check_overflow(STACK* stack)
{
    return (stack->top==(stack->max_size-1));    
}

bool check_underflow(STACK* stack)
{
    return (stack->top==-1);
}

void push(STACK* stack, char item)
{
    if(check_overflow(stack))
    {
        printf("Limit exceeded. Stack size has been increased by one.");
        stack->max_size += 1;
        stack->ptr = (char*)realloc(stack->ptr, (stack->max_size)*sizeof(char));
    }
    stack->ptr[++stack->top] = item;    
}

char pop(STACK* stack)
{
    if(!check_underflow(stack))
        return stack->ptr[stack->top--];
    else
    {
        printf("No items left in stack to pop.");
        exit(0);
    }
}

char peek(STACK* stack)
{
    if(!check_underflow(stack))
        return stack->ptr[stack->top];
    else 
    {
        printf("No items left in stack to peek.");
        exit(0);
    }    
}

void display(STACK* stack)
{
    for(int i = 0; i <= stack->top; i++)
    {
        printf("%c", stack->ptr[i]);
    }
}

void liberate(STACK* stack)
{
    free(stack->ptr);
    free(stack);
}

bool is_operand(char a)
{
    return(isalnum(a));
}

bool is_operator(char a)
{
    return(!isalnum(a));
}

int prec(char op)
{
    switch(op)
    {
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

char* infixtopostfix(char* infix)
{
    STACK* ops = create(10);
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int postind = 0;
    for(int i = 0; infix[i]!='\0'; i++)
    {
        char cur = infix[i];
        if(is_operand(cur))
        {
            postfix[postind++] = infix[i];
        }
        if(is_operator(cur))
        {
            
        }
    }
    while(!check_underflow(ops))
    {
        postfix[postind++] = pop(ops);

        printf("\n");
        display(ops);
    }
    postfix[strlen(infix)] = '\0';
    liberate(ops);
    return postfix;
}

int main() {
    char infix_expression[100];

    // Get infix expression from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix_expression);

    // Convert infix to postfix
    char* postfix_expression = infixtopostfix(infix_expression);

    // Display the results
    printf("Infix Expression: %s\n", infix_expression);
    printf("Postfix Expression: %s\n", postfix_expression);

    // Free memory allocated for postfix_expression
    free(postfix_expression);

    return 0;
}
