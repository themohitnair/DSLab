#include "stackfuncs.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>

bool is_operand(char ops)
{
    return isalnum(ops);
}

bool is_operator(char ops)
{
    return !isalnum(ops);
}

int ctoi(char operand)
{
    return ((int)operand-48);
}

char itoc(int operand)
{
    return ((char)(operand+48));
}

int eval_postfix(char* postfix)
{
    STACK* opers = create(5);
    for(int i = 0; *(postfix+i)!='\0'; i++)
    {
        char cur = *(postfix+i);
        if (is_operand(cur))
        {
            push(opers, cur);
        }
        else if (is_operator(cur))
        {
            int oper2 = ctoi(pop(opers));
            int oper1 = ctoi(pop(opers));

            switch (cur)
            {
                case '+':
                push(opers, itoc(oper1+oper2)); break;
                case '-':
                push(opers, itoc(oper1-oper2)); break;
                case '*':
                push(opers, itoc(oper1*oper2)); break;
                case '/':
                push(opers, itoc(oper1/oper2)); break;
            }
        }
    }
    int result = ctoi(pop(opers));
    liberate(opers);
    return result;
}

int main() {
    char postfix[100];
    
    // Input a postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    int result = eval_postfix(postfix);

    // Display the result
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
