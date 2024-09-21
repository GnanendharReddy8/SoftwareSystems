/*
============================================================================
Name : 32d.c
Author : Gnanendhar Reddy
Description : 32. Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>
#include <sys/sem.h>
sem_t semaphore;

int main() {
    int value;
    sem_init(&semaphore, 0, 1);
    sem_getvalue(&semaphore, &value);

    printf("Semphore created successfully : %d\n",value);

    sem_destroy(&semaphore);

    printf("Semphore destroyed successfully : %d\n",value);


    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ cc 32d.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ ./a.out
Semphore created successfully : 1
Semphore destroyed successfully : 1
*/
