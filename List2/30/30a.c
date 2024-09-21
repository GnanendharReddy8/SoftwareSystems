/*
============================================================================
Name : 30a.c
Author : Gnanendhar Reddy
Description : 30. Write a program to create a shared memory.
a. write some data to the shared memory
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main() {
    int key, shmid;
    char *data;
    key=ftok("file", 97);
    shmid=shmget(key, 1024, IPC_CREAT | 0744);
    data=(char *)shmat(shmid, NULL, 0);
    printf("Enter input : ");
    scanf("%s", data);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ cc 30a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ ./a.out
Enter input : GoodAfternoon!
*/
