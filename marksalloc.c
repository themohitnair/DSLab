//Write a C program to create memory space to read 'n' marks (float) details. Ask the user if marks have to be entered for more than ‘n’ students. If 'yes', then create extra memory space and add data to the array of marks. Print all the marks.

#include<stdio.h>
#include<stdlib.h>

int* alloc_marks(int size) {
    int* marks = (int*)malloc(size*sizeof(int));
    return marks;
}

int* realloc_marks(int* marks, int newsize) {
    marks = (int*)realloc(marks, newsize*sizeof(int));
    return marks;
}

void prompt(int* marks, int start, int end) { 
    for(int i = start; i < end; i++) {
        printf("Enter Marks %d: ", i+1);
        scanf("%d", &marks[i]);
    }
}

void display(int* marks, int start, int end) {
    printf("The marks currently stored are: ");
    for(int i = start; i < end; i++) {
        printf(" %d", marks[i]);
    }
}

int main(void) {
    int n;
    printf("Enter the number of marks to be stored: ");
    scanf("%d", &n);
    int* marks = alloc_marks(n);
    prompt(marks, 0, n);
    display(marks, 0, n);
    
    while(1){
        char choice;    
        printf("\nDo you want to enter more marks? [Y/n]\t");
        scanf(" %c", &choice);
        if ((choice == 'N') || (choice == 'n')) {
            printf("Exiting...\n");
            exit(0);
        }
        else {
            int ext;
            printf("Enter the number of records to be added: ");
            scanf("%d", &ext);
            int temp = n;
            n = n + ext;
            marks = realloc_marks(marks, n);
            prompt(marks, temp, n);
            display(marks, 0, n);
        }
    }
}