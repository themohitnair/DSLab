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

int ctoi(char c)
{
    return (int)(c-'0');
}

char itoc(int c)
{
    return (char)(c+48);
}

int eval(char* postfix)
{
    STACK* opers = create(25);
    for(int i = 0; postfix[i]!='\0'; i++)
    {
        char cur = postfix[i];
        if(operand(cur))
        {
            push(opers, cur);
        }
        if(operator(cur))
        {
            int op2 = ctoi(pop(opers));
            int op1 = ctoi(pop(opers));
            switch (cur)
            {
                case '+':
                    push(opers, itoc(op1+op2));
                    break;
                case '-':
                    push(opers, itoc(op1-op2));
                    break;
                case '*':
                    push(opers, itoc(op1*op2));
                    break;
                case '/':
                    push(opers, itoc(op1/op2));
                    break;
                case '%':
                    push(opers, itoc(op1%op2));
                    break;
                default:
                    printf("Invalid operator. ");
                    exit(0);                 
            }
        }
    }
    return ctoi(pop(opers));
}

int main() 
{
    char postfix[100];    
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = eval(postfix);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

/*Output:
Enter a postfix expression: 16*63/-4+2/
Result of postfix expression: 4
*/