//Write a program to implement stack operations (Array implementation). Display the appropriate messages in case of exceptions. Program should have options to add, remove and display elements of the stack.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    char* s;
    int top;
    int size;
} STACK;

STACK* create(int size) {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->size = size;
    stack->top = -1;
    stack->s = (char*)malloc(stack->size*sizeof(STACK));
    return stack;
}

bool empty(STACK* stack) {
    return (stack->top == -1);
}

bool full(STACK* stack) {
    return (stack->top == (stack->size - 1));
}

void push(STACK* stack, char item) {
    if(full(stack)){
        printf("overflow\n");
        return;
    }
    stack->s[++stack->top] = item;    
}

char pop(STACK* stack) {
    if(empty(stack)) {
        printf("underflow\n");
        return -1;
    }
    return stack->s[stack->top--];
}

char peek(STACK* stack){
    if(empty(stack)) {
        printf("underflow\n");
        return -1;
    }
    return stack->s[stack->top];
}

void display(STACK* stack) {
    if(empty(stack)) {
        printf("underflow\n");
        return;
    }
    printf("\nStack contents: ");
    for(int i = 0; i <= stack->top; i++) {
        printf(" %c", stack->s[i]);
    }
    printf("\n");
}

void liberate(STACK* stack) {
    free(stack->s);
    free(stack);
}

int main(void) {
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    STACK* stack=  create(n);
    printf("STACK MENU\n1. Push element\n2. Pop element\n3. Peek element\n4. Display elements\n5. Exit\n");
    while(1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                char ele;
                printf("\nEnter the item: ");
                scanf(" %c", &ele);
                push(stack, ele);
                break;
            case 2:
                printf("\nPopped element: %c\n", pop(stack));
                break;
            case 3:
                printf("\nTop element: %c\n", peek(stack));
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("\nExiting...");
                liberate(stack);
                exit(0);
            default:
                printf("\nInvalid choice. Try again...\n");
        }
    }
}