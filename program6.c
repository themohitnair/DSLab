#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct {
    int* ptr;
    int front;
    int rear;
    int max_size;
} QUEUE;

QUEUE* create(int max_size)
{    
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->max_size = max_size;
    queue->ptr = (int*)malloc((queue->max_size)*sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

bool is_full(QUEUE* queue)
{
    return (queue->rear == queue->max_size-1);
}

bool is_empty(QUEUE* queue)
{
    return (queue->rear < queue->front);
}

void enqueue(QUEUE* queue, int item)
{
    if(is_full(queue))
    {
        queue->max_size++;
        queue->ptr = (int*)realloc(queue->ptr, (queue->max_size)*sizeof(int));
    }
    queue->ptr[++queue->rear] = item;
}

int dequeue(QUEUE* queue)
{
    if(is_empty(queue))
    {
        printf("The queue has no items left to delete.\n");
        exit(0);
    }
    else
    return queue->ptr[queue->front++];
}

void display(QUEUE* queue)
{
    if(is_empty(queue))
    {
        printf("No items left to display.");
    }
    else
    {
        for(int i = queue->front; i <= queue->rear; i++)
        {
            printf(" %d", queue->ptr[i]);
        }
    }
}

void liberate(QUEUE* queue)
{
    free(queue->ptr);
    free(queue);
}

int main() 
{
    int n;
    printf("Enter the size of the queue you want to create: ");
    scanf("%d", &n);
    QUEUE* q = create(n);
    int choice;
    do {
        printf("1. Enqueue  2. Dequeue  3. Display  0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
            {
                int element;
                printf("Enter the element: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            }
            case 2: 
            {
                int dequeuedElement = dequeue(q);
                printf("Dequeued element: %d\n", dequeuedElement);
                break;
            }
            case 3:
            {
                display(q);
                printf("\n");
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    liberate(q);
    return 0;
}

/*Output:
Enter the size of the queue you want to create: 5
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 1
Enter the element: 12
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 1
Enter the element: 14
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 1
Enter the element: 17
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 1
Enter the element: 19
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 3
 12 14 17 19
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 2
Dequeued element: 12
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 3
 14 17 19
1. Enqueue  2. Dequeue  3. Display  0. Exit
Enter your choice: 0*/