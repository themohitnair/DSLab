#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>

struct node {
    char data;
    struct node* next;
    struct node* prev;
};

struct node* create()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = '-';
    head->next = head;
    head->prev = head;
    return head;
}

void insert_tail(struct node* head, char item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    struct node* tail = head->prev;
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
}

void insert_head(struct node* head, char item)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    struct node* first = head->next;
    head->next = newnode;
    newnode->prev = head;
    newnode->next = first;
    first->prev = newnode;
}

char delete_head(struct node* head)
{
    struct node* del = head->next;
    struct node* next = del->next;
    head->next = next;
    next->prev = head;
    char deleted = del->data;
    free(del);
    return deleted;
}

char delete_tail(struct node* head)
{
    struct node* tail = head->prev;
    struct node* prev = tail->prev;
    prev->next = head;
    head->prev = prev;
    char deleted = tail->data;
    free(tail);
    return deleted;
}

void display(struct node* head)
{
    struct node* ptr = head;
    while(true)
    {
        if(ptr->next == head)
        {
            printf("%c",ptr->data);
            break;
        }
        else
        {
            printf("%c",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void liberate(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=head)
    {
        free(ptr);
        ptr = ptr->next;
    }
    free(head);
}

int main(void)
{
    struct node* head = create();
    int choice;
    char item;
    printf("1. Insert at tail\n2. Insert at head\n3. Delete at tail\n4. Delete at head\n5. Display\n6. Exit\n");
    while(true)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("Enter the item to be inserted: ");
            scanf(" %c",&item);
            insert_tail(head,item);
            break;
            case 2:
            printf("Enter the item to be inserted: ");
            scanf(" %c",&item);
            insert_head(head,item);
            break;
            case 3:
            printf("Deleted element: %c\n",delete_tail(head));
            break;
            case 4:
            printf("Deleted element: %c\n",delete_head(head));
            break;
            case 5:
            display(head);
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid choice. Please choose again.");
        }
    }
}

/*Output:
1. Insert at tail
2. Insert at head
3. Delete at tail
4. Delete at head
5. Display
6. Exit
Enter your choice: 1
Enter the item to be inserted: a
Enter your choice: 1
Enter the item to be inserted: b
Enter your choice: 1
Enter the item to be inserted: c
Enter your choice: 1
Enter the item to be inserted: d
Enter your choice: 5
-abcd
Enter your choice: 2
Enter the item to be inserted: 1
Enter your choice: 2
Enter the item to be inserted: 2
Enter your choice: 2
Enter the item to be inserted: 3
Enter your choice: 2
Enter the item to be inserted: 4
Enter your choice: 5
-4321abcd
Enter your choice: 3
Deleted element: d
Enter your choice: 3
Deleted element: c
Enter your choice: 4
Deleted element: 4
Enter your choice: 4
Deleted element: 3
Enter your choice: 5
-21ab
Enter your choice: 6
*/