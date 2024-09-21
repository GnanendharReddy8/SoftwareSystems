/*
============================================================================
Name : 25.c
Author : Gnanendhar Reddy
Description : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main() {
    key_t key;
    int msqid;
    key = ftok(".", 97);
    msqid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds ms_info;
    msgctl(msqid, IPC_STAT, &ms_info);
    struct ipc_perm permissions = ms_info.msg_perm;
    printf("access permission = %d\n", permissions.mode);
    printf("uid = %d ", permissions.uid);
    printf("gid = %d\n", permissions.gid);
    printf("time of last message sent = %ld\n", ms_info.msg_stime);
    printf("time of last message received = %ld\n", ms_info.msg_rtime);
    printf("time of last change in the message queue = %ld\n", ms_info.msg_ctime);
    printf("size of the queue = %ld\n", ms_info.msg_cbytes);
    printf("number of messages in the queue = %ld\n", ms_info.msg_qnum);
    printf("maximum number of bytes allowed= %ld\n", ms_info.msg_qbytes);
    printf("pid of the msgsnd = %d\n", ms_info.msg_lspid);
    printf("pid of the msgrcv = %d\n", ms_info.msg_lrpid);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/25$ cc 25.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/25$ ./a.out
access permission = 438
uid = 1000 gid = 1000
time of last message sent = 0
time of last message received = 0
time of last change in the message queue = 1726902810
size of the queue = 0
number of messages in the queue = 0
maximum number of bytes allowed= 16384
pid of the msgsnd = 0
pid of the msgrcv = 0
*/
