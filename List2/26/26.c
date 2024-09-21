/*
============================================================================
Name : 26.c
Author : Gnanendhar Reddy
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 10
struct msg_buffer {
    long msg_type;
    char msg_text[100];
}msg;

int main() {
    key_t key;
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.msg_type = 1;
    printf("Enter Data : ");
    fgets(msg.msg_text, MAX, stdin);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Data sent to the message queue : %s \n", msg.msg_text);
    execlp("ipcs", "ipcs", "-q", NULL);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/26$ cc 26.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/26$ ./a.out
Enter Data : Hello Linux!
Data sent to the message queue : Hello Lin 

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610642ec 0          gnanendhar 744        0            0           
0x61064464 1          gnanendhar 666        0            0           
0xffffffff 2          gnanendhar 666        112          1           
*/
