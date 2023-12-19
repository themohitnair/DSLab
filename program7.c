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
    int count;
} CQUEUE;

CQUEUE* create(int max_size)
{    
    CQUEUE* queue = (CQUEUE*)malloc(sizeof(CQUEUE));
    queue->max_size = max_size;
    queue->ptr = (int*)malloc((queue->max_size)*sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

bool is_full(CQUEUE* queue)
{
    return (queue->count == queue->max_size);
}

bool is_empty(CQUEUE* queue)
{
    return (queue->rear < queue->front);
}

void enqueue(CQUEUE* queue, int item)
{
    if(is_full(queue))
    {
        printf("Queue is full.\n");
        exit(0);
    }
    queue->rear = (queue->rear+1)%queue->max_size;
    queue->ptr[queue->rear] = item;
    queue->count++;
}

int dequeue(CQUEUE* queue)
{
    int dequeued;
    if(is_empty(queue))
    {
        printf("The queue has no items left to delete.\n");
        exit(0);
    }
    else    
    dequeued = queue->ptr[queue->front];
    queue->front = (queue->front+1)%queue->max_size;
    queue->count--;
    return dequeued;     
}

void display(CQUEUE* queue)
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

void liberate(CQUEUE* queue)
{
    free(queue->ptr);
    free(queue);
}

#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the circular queue you want to create: ");
    scanf("%d", &n);
    CQUEUE* q = create(n);
    int choice;
    do {
        printf("1. Enqueue  2. Dequeue  3. Display  0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int element;
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            }
            case 2: {
                int dequeuedElement = dequeue(q);
                printf("Dequeued element: %d\n", dequeuedElement);
                break;
            }
            case 3:
                display(q);
                printf("\n");
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    liberate(q);

    return 0;
}

