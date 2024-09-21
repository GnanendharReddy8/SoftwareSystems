/*
============================================================================
Name : 18.c
Author : Gnanendhar Reddy
Description : 18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
    int fd1[2], fd2[2];
    pid_t pid1, pid2;
    if(pipe(fd1) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(fd2) < 0) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    if((pid1=fork()) < 0) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    if (!pid1) {
        dup2(fd1[1], 1);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        char *args[]={"ls", "-l", NULL};
        execv("/bin/ls", args);
    } else {
        if((pid2=fork()) < 0) {
            perror("Fork");
            exit(EXIT_FAILURE);
        }
        if (!pid2) {
            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            close(fd1[1]);
            close(fd2[0]);
            char *args[]={"grep", "^d", NULL};
            execv("/bin/grep", args);
            // execlp("grep", "grep", "^-", NULL);
        } else {
            sleep(2);
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            char *args[]={"wc", "-l", NULL};
            execv("/bin/wc", args);
            // execlp("wc", "wc", "-l", NULL);
        }
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ vim 18.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ cc 18.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ ./a.out
0
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ mkdir sample
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ cc 18.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/18$ ./a.out
1
*/
