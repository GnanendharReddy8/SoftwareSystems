/*
============================================================================
Name : 22.c
Author : Gnanendhar Reddy
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file 
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Could not open the file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Could not create file");
        return 1;
    }

    if (pid == 0) {
        char msg[] = "Writing to the file from the Child process.\n";
        write(fd, msg, sizeof(msg));
    } else {
        char msg[] = "Writing from the Parent process.\n";
        write(fd, msg, sizeof(msg));
    }
    close(fd);

    return 0;
}
/*
nanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 22.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cat output.txt
Writing from the Parent process.
Writing to the file from the Child process.
*/
