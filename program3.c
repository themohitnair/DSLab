#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>

typedef struct {
    int top;
    int max_size;
    char* s;
}STACK;

STACK* create()
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = -1;
    stack->max_size = 1;
    stack->s = (char*)malloc(stack->max_size*sizeof(char));
    return stack;
}

bool underflow(STACK* stack)
{
    return (stack->top == -1);
}

bool overflow(STACK* stack)
{
    return (stack->top == stack->max_size-1);
}

void push(STACK* stack, char item)
{
    if(overflow(stack))
    {
        stack->s = (char*)realloc(stack->s, ++stack->max_size*sizeof(char));
    }
    stack->s[++stack->top] = item;
}

char pop(STACK* stack)
{
    if(underflow(stack))
    {
        printf("Stack is empty. No items left to be deleted.\n");
        exit(0);
    }
    return stack->s[stack->top--];
}

char peek(STACK* stack)
{
    if(underflow(stack))
    {
        printf("Stack is empty. No elements left to peek.\n");
        exit(0);
    }
    return stack->s[stack->top];
}

void display(STACK* stack)
{
    if(underflow(stack))
    {
        printf("Stack is empty. No elements left to display.\n");
        exit(0);
    }
    printf("The elements of the stack are: ");
    for(int i = 0; i<=stack->top; i++)
    {
        printf("%c",stack->s[i]);
    }
}

void liberate(STACK* stack)
{
    free(stack->s);
    free(stack);
}

int main(void)
{
    STACK* stack = create();
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
    while(true)
    {
        int choice;
        char item;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element to be pushed: ");
            scanf(" %c", &item);
            push(stack, item);
            break;
            case 2:
            printf("\nPopped element: %c",pop(stack));
            break;
            case 3: 
            printf("\nTop element: %c", peek(stack));
            break;
            case 4:
            display(stack);
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid choice. Please choose again.\n");
        }
    }
    liberate(stack);
}

/*Output:
1. Push
2. Pop
3. Peek
4. Display
5. Exit

Enter your choice: 1
Enter the element to be pushed: a

Enter your choice: 1
Enter the element to be pushed: b

Enter your choice: 1
Enter the element to be pushed: c

Enter your choice: 1
Enter the element to be pushed: d

Enter your choice: 4
The elements of the stack are: abcd
Enter your choice: 2

Popped element: d
Enter your choice: 2

Popped element: c
Enter your choice: 4
The elements of the stack are: ab
Enter your choice: 3

Top element: b
Enter your choice: 5
*/