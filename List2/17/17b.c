/*
============================================================================
Name : 17b.c
Author : Gnanendhar Reddy
Description : 17. Write a program to execute ls -l | wc.
b. use dup2
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
    if(pid) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        char *args[] = {"wc", NULL};
        execv("/bin/wc", args);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/17$ cc 17b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/17$ ./a.out
      4      29     225
*/
