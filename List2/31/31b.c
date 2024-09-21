/*
============================================================================
Name : 31b.c
Author : Gnanendhar Reddy
Description : 31. Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t counting_semaphore;

    sem_init(&counting_semaphore, 0, 5);

    printf("Counting semaphore created and initialized.\n");

    sem_destroy(&counting_semaphore);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/31$ cc 31b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/31$ ./a.out
Counting semaphore created and initialized.
*/
