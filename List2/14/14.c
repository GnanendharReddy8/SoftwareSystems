/*
============================================================================
Name : 14.c
Author : Gnanendhar Reddy
Description : 14.Write a simple program to create a pipe, write to the pipe, 
read from pipe and display on the monitor.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int fd[2];
    char msg[]="Hello World!\n\0";
    char buf[50];
    if(pipe(fd) == -1) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    write(fd[1], msg, strlen(msg));
    read(fd[0], buf, strlen(msg));
    printf("%s", buf);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/14$ cc 14.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/14$ ./a.out
Hello World!
*/
