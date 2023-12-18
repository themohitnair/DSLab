#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

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

bool is_operand(char o)
{
    return isalnum(o);
}

bool is_operator(char op)
{
    return !isalnum(op);
}

int eval_postfix (char* postfix)
{
    CSTACK* eval = create_stack(200);
    for(int i = 0; *(postfix+i)!= '\0'; i++)
    {
        char cur = *(postfix+i);
        if (is_operand(cur))
        {
            push(eval, cur);
        }
        if (is_operator(cur))
        {
            int o1 = (int)pop(eval);
            int o2 = (int)pop(eval);
            switch (cur)
            {
            case '+':
            {
                push(eval, o1+o2);
                break;
            }                
            case '-':
            {
                push(eval, o1-o2);
                break;
            }
            case '*':
            {
                push(eval, o1*o2);
                break;
            }
            case '/':
            {
                push(eval, o1/o2);
                break;
            }
            case '^':
            {
                push(eval, pow(o1, o2));
                break;
            }
            default:
                printf("Invalid character!");
                exit(0);
            }
        }
    }
    return (int)(pop(eval));
}

int main(void)
{
    char* postfix;
    printf("Enter postfix expression: ");
    scanf("%[^\n]", postfix);
    printf("Evaluation of postfix expression yields: %d. ", eval_postfix(postfix));
}
