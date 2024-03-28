//Define a structure student with fields name, usn, age, cgpa. Create an array of students and display them. Prompt the user for cgpa and display student details greater than or equal to the cgpa.

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char* name;
    char* usn;
    float cgpa;
    int age;
} STUDENT;

STUDENT* alloc_student(int n) {
    STUDENT* student = (STUDENT*)malloc(n*sizeof(STUDENT));
    for(int i = 0; i < n; i++) {
        (student+i)->name = (char*)malloc(25*sizeof(char));
        (student+i)->usn = (char*)malloc(10*sizeof(char));
    }
        return student;
}

STUDENT* init_student(STUDENT* student, int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter the name of the student %d: ", i+1);
        scanf(" %[^\n]", (student+i)->name);
        printf("Enter the USN of the student %d: ", i+1);
        scanf(" %[^\n]", (student+i)->usn);
        printf("Enter the age of the student %d: ", i+1);
        scanf("%d", &(student+i)->age);
        printf("Enter student %d's CGPA: ", i+1);
        scanf("%f", &(student+i)->cgpa);
        printf("\n");
    }
    return student;
}

void disp_student(STUDENT* student, int n, float cgpa) {
    for(int i = 0; i < n; i++) {
        if((student+i)->cgpa >= cgpa) {
            printf("#####-STUDENT %d-#####\n", i+1);
            printf("Name: %s\n", (student+i)->name);
            printf("USN: %s\n", (student+i)->usn);
            printf("Age: %d\n", (student+i)->age);
            printf("CGPA: %.2f\n", (student+i)->cgpa);
            printf("\n");
        }        
    }
}

int main(void) {
    int n;
    printf("Enter the number of students whose records need to be entered: ");
    scanf("%d", &n);
    STUDENT* student = alloc_student(n);
    student = init_student(student, n);

    float cgpa_c;
    printf("Enter CGPA criteria: ");
    scanf("%f", &cgpa_c);

    printf("The students with CGPA greater than %.2f are: \n",cgpa_c);
    disp_student(student, n, cgpa_c);
}