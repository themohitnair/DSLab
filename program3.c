#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

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

int main(void)
{
    int n, max;
    CSTACK* stack;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);
    getchar();
    stack = create_stack(max);
    printf("Enter the number of elements to be pushed into the stack: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the elements to be pushed into the stack: ");
    char tmp = 'c';
    for(int i = 0; i < n; i++)
    {
        scanf("%c", &tmp);
        push(stack, tmp);
    }
    printf("The state of the stack is: ");
    disp_stack(stack);

    printf("Enter the number of elements to be popped: ");
    scanf("%d", &n);
    printf("The popped elements are: ");
    for(int i = 0; i < n; i++)
    {
        printf("%c ", pop(stack));
    }
    liberate_stack(stack);
}