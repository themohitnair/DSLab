#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a;
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    a = (int *)calloc(n, sizeof(int));
    if (a == NULL) {
        printf("Memory not allocated. ");
        exit(0);
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    char choice;
    while ((getchar()) != '\n');

    printf("Do you want to continue? (y/n) ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int add;
        printf("Enter the number of cells to be added: ");
        scanf("%d", &add);

        a = (int *)realloc(a, (n + add) * sizeof(int));

        printf("Enter the elements to be added: ");
        for (int i = 0; i < add; i++) {
            scanf("%d", &a[n + i]);
        }

        n = n + add;
    }

    printf("Finally, the elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }

    free(a);

    return 0;
}



/*Output: Enter the number of elements in the array: 5
Enter the elements of the array: 1 2 4 5 6
Do you want to continue? (y/n) y
Enter the number of cells to be added: 4
Enter the elements to be added: 3 5 6 7
Finally, the elements in the array are: 1  2  4  5  6  3  5  6  7*/

