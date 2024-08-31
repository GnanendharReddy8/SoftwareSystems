/*
============================================================================
Name : 30.c
Author : Gnanendhar Reddy
Description : Write a program to run a script at a specific time using a Daemon process. 
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    pid_t pid = 0;
    pid_t sid = 0;
    int fd = open("test.txt",O_WRONLY);
    pid = fork();
    if(pid < 0) {
        perror("Failed to create child process : ");
        exit(1);
    }
    
    if(pid > 0) {
        printf("The process id of the parent is %d \n",pid);
        exit(0);
    }

    sleep(5);
    umask(0);
    sid = setsid();
    
    if(sid < 0) {
        exit(0);
    }
    
    chdir("/home/kanishka/abc/30");
    close(0);
    close(1);
    close(2);
    
    while(1) {
        sleep(2);
        write(fd,"this is deamon\n",15);
    }
    return 0;    
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 30.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
The process id of the parent is 8860 
*/
