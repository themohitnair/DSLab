#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

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
    if(!check_overflow(stack))
        stack->ptr[++stack->top] = item;
    else
    {
        printf("Limit exceeded. Stack size has been increased by one.");
        stack->max_size += 1;
        stack->ptr = (char*)realloc(stack->ptr, (stack->max_size)*sizeof(char));
    }
}

char pop(STACK* stack)
{
    if(check_underflow(stack))
    {
        printf("No items left in stack to pop.\n");
        exit(0);
    }        
    else
    {
        return stack->ptr[stack->top--];
    }
}

char peek(STACK* stack)
{
    if(check_underflow(stack))
    {
        printf("No items left in stack.\n");
        exit(0);
    }        
    else
        return stack->ptr[stack->top];
}

void display(STACK* stack)
{
    if(check_underflow(stack))
    {
        printf("No items left in stack.\n");
        exit(0);
    }
    else
    {
        for(int i = 0; i <= stack->top; i++)
        {
            printf("%c", stack->ptr[i]);
        }        
    }
    
}

void liberate(STACK* stack)
{
    free(stack->ptr);
    free(stack);
}

/*Output:
Enter a postfix expression: 12+3*2-
Result of postfix expression: 7*/