/*
========================================================================================
Name : 15.c
Author : Gnanendhar Reddy
Description : 15.Write a simple program to send some data from parent to the child process
Date: 21st Sep, 2024.
========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

int main() {
    int fd[2];
    if(pipe(fd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if(pid==0) { // child
        char buf[100];
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Parent says, %s\n", buf);
    }
    else {
        char buf[100]="\"I am writing!\"\0";
        close(fd[0]);
        write(fd[1], buf, strlen(buf));
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2$ cc 15.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2$ ./a.out
Parent says, "I am writing!"
*/
