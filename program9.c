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

bool empty(struct node* head)
{
    return (head->next == head && head->prev == head);
}

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

void insert_pos(struct node* head, char item, int pos)
{
    struct node* ptr = head;
    while(pos!=0)
    {
        ptr = ptr->next;
        pos--;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    struct node* next = ptr->next;
    ptr->next = newnode;
    newnode->prev = ptr;
    newnode->next = next;
    next->prev = newnode;
}

char delete_head(struct node* head)
{
    if(empty(head))
    {
        printf("List is empty. No items left to delete.");
        exit(0);
    }
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
    if(empty(head))
    {
        printf("List is empty. No items left to delete.");
        exit(0);
    }
    struct node* tail = head->prev;
    struct node* prev = tail->prev;
    prev->next = head;
    head->prev = prev;
    char deleted = tail->data;
    free(tail);
    return deleted;
}

char delete_pos(struct node* head, int pos)
{
    if(empty(head))
    {
        printf("List is empty. No items left to delete.");
        exit(0);
    }
    struct node* ptr = head;
    while(pos!=0)
    {
        ptr = ptr->next;
        pos--;
    }
    struct node* prev = ptr->prev;
    struct node* next = ptr->next;
    char deleted = ptr->data;
    prev->next = next;
    next->prev = prev;
    free(ptr);
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

int search(struct node* head, char item)
{
    if(empty(head))
    {
        printf("List is empty. No items left to delete.");
        exit(0);
    }
    int count = 1;
    int flag = 0;
    struct node* ptr = head->next;
    while(true)
    {
        if(ptr->data == item)
        {
            flag = 1;
            break;
        }
        else
        {
            count++;
            ptr = ptr->next;
        }    
        if(ptr == head)
        {
            break;
        }
    }
    if(flag)
    return count;
    else
    return -1;
}

void liberate(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=head)
    {
        struct node* memo = ptr->next;
        free(ptr);
        ptr = memo;
    }
    free(head);
}

int main(void)
{
    struct node* head = create();
    int choice, pos;
    char item;
    printf("1. Insert at tail\n2. Insert at head\n3. Insert after position\n4. Delete at tail\n5. Delete at head\n6. Delete at position\n7. Search for an element\n8. Display\n9. Exit\n");
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
            printf("Enter the item to be inserted: ");
            scanf(" %c",&item);
            printf("Enter the position after which item is to be inserted: ");
            scanf("%d", &pos);
            insert_pos(head, item, pos);
            break;
            case 4:
            printf("Deleted element: %c\n",delete_tail(head));
            break;
            case 5:
            printf("Deleted element: %c\n",delete_head(head));
            break;
            case 6:
            printf("Enter the position at which item is to be deleted: ");
            scanf("%d", &pos);
            printf("Deleted element: %c\n",delete_pos(head, pos));
            break;
            case 7:
            printf("Enter the element to be searched: ");
            scanf(" %c",&item);
            printf("The element is found at node %d of the list.\n",search(head, item));
            break;
            case 8:
            display(head);
            break;
            case 9:
            exit(0);
            default:
            printf("Invalid choice. Please choose again.");
        }
    }
    liberate(head);
}

/*Output:
1. Insert at tail
2. Insert at head
3. Insert after position
4. Delete at tail
5. Delete at head
6. Delete at position
7. Search for an element
8. Display
9. Exit
Enter your choice: 1
Enter the item to be inserted: a
Enter your choice: 1
Enter the item to be inserted: b
Enter your choice: 1
Enter the item to be inserted: c
Enter your choice: 1
Enter the item to be inserted: d
Enter your choice: 2
Enter the item to be inserted: 1
Enter your choice: 2
Enter the item to be inserted: 2
Enter your choice: 2
Enter the item to be inserted: 3
Enter your choice: 2
Enter the item to be inserted: 4
Enter your choice: 8
-4321abcd
Enter your choice: 3
Enter the item to be inserted: 0
Enter the position after which item is to be inserted: 4
Enter your choice: 8
-43210abcd
Enter your choice: 4
Deleted element: d
Enter your choice: 4
Deleted element: c
Enter your choice: 5
Deleted element: 4
Enter your choice: 5
Deleted element: 3
Enter your choice: 8
-210ab
Enter your choice: 6
Enter the position at which item is to be deleted: 3
Deleted element: 0
Enter your choice: 8
-21ab
Enter your choice: 1
Enter the item to be inserted: f
Enter your choice: 1
Enter the item to be inserted: g
Enter your choice: 7
Enter the element to be searched: a
The element is found at node 3 of the list.
Enter your choice: 8
-21abfg
Enter your choice: 9*/