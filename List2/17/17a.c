/*
============================================================================
Name : 17a.c
Author : Gnanendhar Reddy
Description : 17. Write a program to execute ls -l | wc.
a. use dup
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    if(pipe(fd) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if (!pid) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        close(fd[0]);
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/17$ cc 17a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/17$ ./a.out
      3      20     153
*/
