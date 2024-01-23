#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

struct node {
    char data;
    struct node* link;
};

struct node* create()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = '-';
    head->link = NULL;
    return head;
}

bool empty(struct node* head)
{
    return head->link == NULL;
}

void enqueue(struct node* head, char item)
{
    struct node* ptr = head;
    while(true)
    {
        if(ptr->link == NULL)
            break;
        else
            ptr = ptr->link;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;
    ptr->link = newnode;
}


char dequeue(struct node* head)
{
    if(empty(head))
    {
        printf("No items left to be deleted. List is empty.");
        exit(0);
    }
    struct node* ptr = head;
    struct node* del = head->link;
    struct node* newfirst = del->link;
    ptr->link = newfirst;
    char deleted = del->data;
    free(del);
    return deleted;
}

void display(struct node* head)
{
    if(empty(head))
    {
        printf("No items left to be displayed. List is empty.");
        exit(0);
    }
    struct node* ptr = head->link;
    printf("The contents of the list are: ");
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

char get_item()
{
    char item;
    printf("Enter the item: ");
    scanf(" %c",&item);
    return item;
}

void liberate(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)    
    {
        struct node* memo = ptr->link;
        free(ptr);
        ptr = memo;
    }
}

int main(void)
{
    struct node* head = create();
    int choice;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(true)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue(head,get_item());
            break;

            case 2:
            printf("Deleted element: %c\n",dequeue(head));
            break;

            case 3:
            display(head);
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid choice. Please choose again.");
        }
    }
    liberate(head);
}

/*Output:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the item: a
Enter your choice: 1
Enter the item: b
Enter your choice: 1
Enter the item: c
Enter your choice: 1
Enter the item: d
Enter your choice: 3
The contents of the list are: abcd
Enter your choice: 2
Deleted element: a
Enter your choice: 2
Deleted element: b
Enter your choice: 3
The contents of the list are: cd
Enter your choice: 4
*/