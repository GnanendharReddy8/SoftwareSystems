/*
============================================================================
Name : 28.c
Author : Gnanendhar Reddy
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    int maxpriority, minpriority;

    maxpriority = sched_get_priority_max(SCHED_FIFO);
    if (maxpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    minpriority = sched_get_priority_min(SCHED_FIFO);
    if (minpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    printf("Max. priority: %d\n", maxpriority);
    printf("Min. priority: %d\n", minpriority);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 28.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Max. priority: 99
Min. priority: 1
*/
