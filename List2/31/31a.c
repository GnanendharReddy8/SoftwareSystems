/*
============================================================================
Name : 31a.c
Author : Gnanendhar Reddy
Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t binary_semaphore;

    sem_init(&binary_semaphore, 0, 1);

    printf("Binary semaphore created and initialized.\n");

    sem_destroy(&binary_semaphore);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/31$ cc 31a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/31$ ./a.out
Binary semaphore created and initialized.
*/
