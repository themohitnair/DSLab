#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct {
    char* s;
    int top;
    int max_size;
} STACK;

STACK* create(int max)
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->max_size = max;
    stack->s = (char*)malloc(stack->max_size*sizeof(char));
    stack->top = -1;
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
    if (overflow(stack))
    {
        printf("Stack is full.\n");
        exit(0);
    }
    stack->s[++stack->top] = item;
}

char pop(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    return (stack->s[stack->top--]);
}

char peek(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    return (stack->s[stack->top]);
}

void disp(STACK* stack)
{
    if (underflow(stack))
    {
        printf("Stack is empty.\n");
        exit(0);
    }
    for(int i = 0; i <= stack->top; i++)
    {
        printf("%c",stack->s[i]);
    }
}

void liberate(STACK* stack)
{
    free(stack->s);
    free(stack);
}

int prec(char ops)
{
    switch (ops)
    {
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

bool operand(char ops)
{
    return (isalnum(ops));
}

bool operator(char ops)
{
    return !operand(ops);
}

char* conv_postfix(char* infix)
{
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int ind = 0;
    STACK* ops = create(20);
    for(int i = 0; infix[i]!='\0'; i++)
    {
        char cur = infix[i];
        if(operand(cur))
        {
            postfix[ind++] = cur;
        }
        else if (cur == '(')
        {
            push(ops, cur);
        }
        else if (cur == ')')
        {
            while(!underflow(ops) && peek(ops)!='(')
            {
                postfix[ind++] = pop(ops);
            }
            char g = pop(ops);
        }
        else if(operator(cur))
        {
            while(!underflow(ops) && prec(cur)<=prec(peek(ops)))
            {
                postfix[ind++] = pop(ops);
            }
            push(ops, cur);
        }
    }
    while (!underflow(ops))
    {
        postfix[ind++] = pop(ops);
    }
    postfix[ind] = '\0';
    liberate(ops);
    return postfix;
}

int main() 
{
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char* postfix = conv_postfix(infix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    free(postfix);
    return 0;
}

/*Output:
Enter an infix expression: (a+b)*c-d/(e-f)+R%K
Infix Expression: (a+b)*c-d/(e-f)+R%K
Postfix Expression: ab+c*def-/-RK%+
*/