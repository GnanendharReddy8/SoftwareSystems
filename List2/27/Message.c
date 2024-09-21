#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#define MAX 10 

struct mbuffer {
    long mtype;
    char mtext[100];
} message;

int main() {
    key_t key; 
    int msgid;
    key = ftok("file", 97);
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mtype = 1; 
    printf("Write Data : "); 
    fgets(message.mtext, MAX, stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Data send : %s", message.mtext);
}
