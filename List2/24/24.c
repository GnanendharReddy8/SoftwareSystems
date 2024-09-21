/*
============================================================================
Name : 24.c
Author : Gnanendhar Reddy
Description : 24. Write a program to create a message queue and print the key and message queue id.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

int main() {
    int msgid;
    key_t key;
    key=ftok(".", 97);
    msgid=msgget(key, IPC_CREAT | 0744);
    printf("Key = %d\nMessage queue id = %d", key, msgid);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/24$ cc 24.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/24$ ./a.out
Key = 1627800300
Message queue id = 0
*/
