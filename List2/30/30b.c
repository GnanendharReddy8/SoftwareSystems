/*
============================================================================
Name : 30b.c
Author : Gnanendhar Reddy
Description : 30. Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
    shmid=shmget(key, 1024, 0);
    data=(char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Shared memory input : %s\n", data);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ cc 30b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/30$ ./a.out
Shared memory input : GoodAfternoon!
*/
