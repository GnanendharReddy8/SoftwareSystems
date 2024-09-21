/*
============================================================================
Name : 28.c
Author : Gnanendhar Reddy
Description : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    struct ipc_perm *permissions = &ms_info.msg_perm;
    printf("Current permission : %d\n", permissions->mode);
    permissions->mode = 777;
    ms_info.msg_perm = *permissions;
    msgctl(msqid, IPC_SET, &ms_info);
    printf("Changed permissions\n");
    msgctl(msqid, IPC_STAT, &ms_info);
    printf("New permission : %d \n", permissions->mode);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/28$ cc 28.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/28$ ./a.out
Current permission : 438
Changed permissions
New permission : 265 
*/
