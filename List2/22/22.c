/*
============================================================================
Name : 22.c
Author : Gnanendhar Reddy
Description : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/time.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    retval = select(1, &rfds, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (retval) {
        printf("Received data within 10 seconds\n");
    } else {
        printf("No data received within 10 seconds\n");
        exit(EXIT_SUCCESS);
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/22$ cc 22.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/22$ ./a.out
Hello!
Received data within 10 seconds
*/
