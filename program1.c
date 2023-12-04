#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct {
	char name[25]; 
	char usn[10];
	int age;
	int marks[5];
	float sgpa;
} STUDENT;

void readstudent(STUDENT *s)
{
	int i;
	printf("Enter the name of the student: ");
	scanf("%s", s->name);
	printf("Enter the USN of the student: ");
	scanf("%s", s->usn);
	printf("Enter the age of the student: ");
	scanf("%d", &s->age);
	printf("Enter the marks of the student in 5 subjects: ");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &s->marks[i]);
	}
	s->sgpa = 0;
	for(i=0;i<5;i++)
	{
		s->sgpa+=s->marks[i];
	}
	s->sgpa/=50;
}

void printstudent(STUDENT s)
{
	printf("-----Student Details of %s-----\n",s.name);
	printf("USN: %s\nAge: %d\nSGPA: %f\n", s.usn,s.age,s.sgpa);
}

void main()
{
	int i, n;
	STUDENT *s;
	printf("Enter the number of students whose data is to be entered: ");
	scanf("%d", &n);
	s = (STUDENT *)malloc(n*sizeof(STUDENT));
	for(i = 0; i<n; i++)
	{
		readstudent(&s[i]);
	}
	for(i = 0; i<n; i++)
	{
		printstudent(s[i]);
	}
}


/*Output: 
Enter the number of students whose data is to be entered: 2
Enter the name of the student: A
Enter the USN of the student: 123
Enter the age of the student: 18
Enter the marks of the student in 5 subjects: 98 99 99 98 99
Enter the name of the student: B
Enter the USN of the student: 456
Enter the age of the student: 18
Enter the marks of the student in 5 subjects: 99 80 98 99 100
-----Student Details of A-----
USN: 123
Age: 18
SGPA: 9.860000
-----Student Details of B-----
USN: 456
Age: 18
SGPA: 9.520000*/

