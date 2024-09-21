/*
============================================================================
Name : 29.c
Author : Gnanendhar Reddy
Description : 29. Write a program to remove the message queue.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main() {
    int queue_id;
    queue_id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    printf("Message id = %d\n", queue_id);
    if (queue_id == -1) {
        perror("msgget");
        exit(1);
    }
    if(msgctl(queue_id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    char *args[] = {"ipcs", "-q", NULL};
    execv("/bin/ipcs", args);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/29$ cc 29.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/29$ ./a.out
Message id = 5

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610642ec 0          gnanendhar 744        0            0           
0x61064464 1          gnanendhar 666        0            0           
0xffffffff 2          gnanendhar 666        112          1           
0x61064448 3          gnanendhar 411        0            0           
*/
