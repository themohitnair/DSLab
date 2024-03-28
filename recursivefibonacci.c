//Write recursive C program i. To generate Fibonacci series

#include<stdio.h>
#include<stdlib.h>

int fib(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    else if (n > 1) {
        return fib(n-1) + fib(n-2);
    }
    else {
        return -1;
    }
}

int main(void) {
    int n;
    printf("Enter the number of terms in the Fibonacci Series to be printed: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf(" %d", fib(i));
    }
    printf("\n");
}