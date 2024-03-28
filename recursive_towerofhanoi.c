//Write recursive C program ii. To print the disk movements in the tower of Hanoi problem for 'n' disks.

#include<stdio.h>
#include<stdlib.h>

int towerofhanoi(int disks, char frompeg, char auxpeg, char topeg) {
    int count = 0;
    if(disks == 1) {
        printf("disk %d: char %c to %c\n", disks, frompeg, topeg);
        return 1;
    }
    else if(disks > 1){
        count += towerofhanoi(disks-1, frompeg, topeg, auxpeg);
        printf("disk %d: char %c to %c\n", disks, frompeg, topeg);
        count++;
        count += towerofhanoi(disks-1, auxpeg, topeg, frompeg);
    }
    else {
        printf("Invalid number of disks. ");
    }
    return count;
}

int main(void) {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The total number of disk movements for %d disks is %d.\n", n, towerofhanoi(n, 'A', 'B', 'C'));
}