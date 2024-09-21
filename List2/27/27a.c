/*
============================================================================
Name : 27a.c
Author : Gnanendhar Reddy
Description : 27. Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mbuffer {
    long mtype;
    char mtext[100];
} message;

int main() {
    key_t key;
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Data Received : %s\n", message.mtext);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ cc Message.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ ./a.out
Write Data : Hello!
Data send : Hello!
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ cc Message.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ ./a.out
Write Data : Howdy?
Data send : Howdy?
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ cc 27a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/27$ ./a.out
Data Received : Hello!
*/
