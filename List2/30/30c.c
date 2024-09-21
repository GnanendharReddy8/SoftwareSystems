/*
============================================================================
Name : 30c.c
Author : Gnanendhar Reddy
Description : 30. Write a program to create a shared memory.
c. detach the shared memory
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main() {
    key_t key = ftok("file", 97);
    int shmid = shmget(key, 1024, 0);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data : %s\n", str);
    shmdt(str);
    printf("Shared memory detached...\n");
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ cc 30c.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ ./a.out
Data : GoodAfternoon!
Shared memory detached...
*/
