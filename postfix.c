//Write a program to convert and print a given valid parenthesized infix arithmetic expression to postfix expression. The expression consists of single character operands and binary operators + - * /. Apply the concept of stack data structure to solve this problem.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

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

void liberate(STACK* stack) {
    free(stack->s);
    free(stack);
}

int prec(char op) {
    switch(op) {
        case '*':
        case '%':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool opnd(char op) {
    return (isalnum(op));
}

bool optr(char op) {
    return (op == '*' || op == '-' || op == '/' || op == '%' || op == '+');
}

char* postfix(char* infix) {
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int ind = 0;
    STACK* stack = create(30);
    for(int i = 0; infix[i] != '\0'; i++) {
        char cur = infix[i];
        if(opnd(cur)) {
            postfix[ind++] = cur;
        }
        else if(cur == '(') {
            push(stack, cur);
        }
        else if(cur == ')') {
            while(!empty(stack) && peek(stack)!='(') {
                postfix[ind++] = pop(stack);
            }
            char garbage = pop(stack);
        }
        else if(optr(cur)) {
            while(!empty(stack) && (prec(peek(stack)) >= prec(cur))) {
                postfix[ind++] = pop(stack);
            }
            push(stack, cur);
        }
    }
    while(!empty(stack)) {
        postfix[ind++] = pop(stack);
    }
    postfix[ind] = '\0';
    liberate(stack);
    return postfix;
}

int main(void) {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%[^\n]", infix);
    printf("The resulting postfix expression is: %s\n", postfix(infix));
}