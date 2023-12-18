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

int main() 
{
    int n;
    printf("Enter the size of the stack you want to create: ");
    scanf("%d", &n);
    STACK* myStack = create(n);
    char input;
    do {
        printf("1. Push  2. Pop  3. Peek  4. Display  0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &input);
        switch (input) {
            case '1': {
                char element;
                printf("Enter the element to push: ");
                scanf(" %c", &element);
                push(myStack, element);
                break;
            }
            case '2': 
            {
                char poppedElement = pop(myStack);
                printf("Popped element: %c\n", poppedElement);
                break;
            }
            case '3':
                char peekedElement = peek(myStack);
                printf("TOP element: %c\n", peekedElement);
                break;
            case '4':
                printf("Stack content: ");
                display(myStack);
                printf("\n");
                break;
            case '0':
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } 
    while (input != '0');
    liberate(myStack);

    return 0;
}

/*Output:
Enter the size of the stack you want to create: 5
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 1
Enter the element to push: a
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 1
Enter the element to push: b
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 1
Enter the element to push: c
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 1
Enter the element to push: d
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 2
Popped element: d
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 3
TOP element: c
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 4
Stack content: abc
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 0
*/