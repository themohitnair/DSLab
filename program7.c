#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>

typedef struct {
    char* q;
    int f;
    int r;
    int max_size;
    int count;
}CQUEUE;

CQUEUE* create(int max)
{
    CQUEUE* queue = (CQUEUE*)malloc(sizeof(CQUEUE));
    queue->max_size = max;
    queue->f = 0;
    queue->r = -1;
    queue->count = 0;
    queue->q = (char*)malloc(queue->max_size*sizeof(char));
    return queue;
}

bool full(CQUEUE* queue)
{
    return queue->count == queue->max_size;
}

bool empty(CQUEUE* queue)
{
    return queue->count == 0;
}

void enqueue(CQUEUE* queue, char item)
{
    if (full(queue))
    {
        printf("Queue is full. No space to insert elements.\n");
        exit(0);
    }
    queue->r = (queue->r+1)%queue->max_size;
    queue->q[queue->r] = item;
    queue->count++;
}

char dequeue(CQUEUE* queue)
{
    if (empty(queue))
    {
        printf("Queue is empty. No items left to delete.\n");
        exit(0);
    }
    char dequeued = queue->q[queue->f];
    queue->f = (queue->f+1)%queue->max_size;
    queue->count--;
    return dequeued;
}

void display(CQUEUE* queue)
{
    if (empty(queue))
    {
        printf("Queue is empty. No items left to display.\n");
        exit(0);
    }
    printf("The elements in the circular queue are: ");
    for(int i = 0; i<queue->count; i++)
    {
        printf("%c",queue->q[(i+queue->f)%queue->max_size]);
    }
}

void liberate(CQUEUE* queue)
{
    free(queue->q);
    free(queue);
}

int main(void)
{
    int size;
    printf("Enter the maximum size of the queue: ");
    scanf("%d",&size);
    CQUEUE* queue = create(size);
    char item;
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(true)    
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the character to be inserted into the queue: ");
            scanf(" %c", &item);
            enqueue(queue, item);
            break;

            case 2:
            printf("Dequeued element: %c",dequeue(queue));
            break;

            case 3:
            display(queue);
            break;

            case 4:
            liberate(queue);
            exit(0);

            default:
            printf("Invalid choice. Please choose again.\n");
        }
    }
    liberate(queue);
}

/*Output:
Enter the maximum size of the queue: 5
1. Enqueue
2. Dequeue
3. Display
4. Exit

Enter your choice: 1
Enter the character to be inserted into the queue: a

Enter your choice: 1
Enter the character to be inserted into the queue: b

Enter your choice: 1
Enter the character to be inserted into the queue: c

Enter your choice: 1
Enter the character to be inserted into the queue: d

Enter your choice: 2
Dequeued element: a
Enter your choice: 2
Dequeued element: b
Enter your choice: 3
The elements in the circular queue are: cd
Enter your choice: 1
Enter the character to be inserted into the queue: e

Enter your choice: 1
Enter the character to be inserted into the queue: f

Enter your choice: 3
The elements in the circular queue are: cdef
Enter your choice: 1
Enter the character to be inserted into the queue: 5

Enter your choice: 1
Enter the character to be inserted into the queue: 7
Queue is full. No space to insert elements.*/
