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
    if(check_overflow(stack))
    {
        stack->max_size += 1;
        stack->ptr = (char*)realloc(stack->ptr, (stack->max_size)*sizeof(char));
    }
    stack->ptr[++stack->top] = item;
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
    STACK* q = create(n);
    char input;
    printf("1. Push  2. Pop  3. Peek  4. Display  0. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf(" %c", &input);
        switch (input) {
            case '1': {
                char element;
                printf("Enter the element to push: ");
                scanf(" %c", &element);
                push(q, element);
                break;
            }
            case '2': 
            {
                char poppedElement = pop(q);
                printf("Popped element: %c\n", poppedElement);
                break;
            }
            case '3':
                char peekedElement = peek(q);
                printf("TOP element: %c\n", peekedElement);
                break;
            case '4':
                display(q);
                printf("\n");
                break;
            case '0':
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } 
    while (input != '0');
    liberate(q);

    return 0;
}

/*Output:
Enter the size of the stack you want to create: 5
1. Push  2. Pop  3. Peek  4. Display  0. Exit
Enter your choice: 1
Enter the element to push: a
Enter your choice: 1
Enter the element to push: b
Enter your choice: 1
Enter the element to push: c
Enter your choice: 1
Enter the element to push: d
Enter your choice: 2
Popped element: d
Enter your choice: 3
TOP element: c
Enter your choice: 4
abc
Enter your choice: 0
*/