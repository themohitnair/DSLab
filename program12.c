#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

struct node {
    int data;
    struct node* right;
    struct node* left;    
};

bool empty(struct node* root) {
    return (root == NULL);
}

struct node* create(int item) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = item;
    root->right = NULL;
    root->left = NULL;
    return root;
}

struct node* insert(struct node* root, int item) {
    if(empty(root)) {
        root = create(item);
        return root;
    }
    else {
        if(item > root->data) {
            root->right = insert(root->right, item);
        }
        else if(item < root->data) {
            root->left = insert(root->left, item);
        }
        return root;
    }
}

void preorder(struct node* root) {
    if(empty(root)) {
        return;
    }
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node* search (struct node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }
    else {
        if (key > root->data) {
            return search(root->right, key);
        }
        else if (key < root->data) {
            return search(root->left, key);
        }
    }
}

void inorder(struct node* root) {
    if(empty(root)) {
        return;
    }
    inorder(root->left);
    printf(" %d", root->data);    
    inorder(root->right);
}

void postorder(struct node* root) {
    if(empty(root)) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);    
}

void liberate(struct node* root) {
    if(empty(root)) {
        return;
    }
    liberate(root->left);
    liberate(root->right);
    free(root);
}

int main(void) {
    struct node* root;
    int choice, item, r;
    printf("Enter the value of the root node: ");
    scanf("%d", &r);
    root = create(r);
    printf("1. Insert node\n2. Search node\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");

    while(true) {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
            printf("Enter the item: ");
            scanf("%d", &item);
            insert(root, item);
            break;

            case 2:
            printf("Enter the item: ");
            scanf("%d", &item);
            if(search(root, item) == NULL) {
                printf("Item not found! \n");
            }
            else {
                printf("Item found! \n");
            }
            break;

            case 4:
            inorder(root);
            printf("\n");
            break;
            
            case 5:
            preorder(root);
            printf("\n");
            break;

            case 6:
            postorder(root);
            printf("\n");
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("Invalid value. Please Enter again.");
        }
    }

    liberate(root);
}

/*Output:
Enter the value of the root node: 5
1. Insert node
2. Search node
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 1
Enter the item: 3
Enter your choice: 1
Enter the item: 7
Enter your choice: 1
Enter the item: 2
Enter your choice: 1
Enter the item: 4
Enter your choice: 1
Enter the item: 6
Enter your choice: 1
Enter the item: 8
Enter your choice: 2
Enter the item: 3
Item found! 
Enter your choice: 2   
Enter the item: 10
Item not found! 
Enter your choice: 4
 2 3 4 5 6 7 8
Enter your choice: 5
 5 3 2 4 7 6 8
Enter your choice: 6
 2 4 3 6 8 7 5
Enter your choice: 7*/