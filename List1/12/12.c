/*
============================================================================
Name : 12.c
Author : Gnanendhar Reddy
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 30th Aug, 2024
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Failed to get file status flags");
        close(fd);
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    if (flags & O_RDONLY) {
        printf("File opened in read-only mode.\n");
    }
    if (flags & O_WRONLY) {
        printf("File opened in write-only mode.\n");
    }
    if (flags & O_RDWR) {
        printf("File opened in read-write mode.\n");
    }
    if (flags & O_APPEND) {
        printf("File opened in append mode.\n");
    }
    if (flags & O_CREAT) {
        printf("File created if it does not exist.\n");
    }
    if (flags & O_EXCL) {
        printf("File is opened with exclusive creation.\n");
    }
    if (flags & O_TRUNC) {
        printf("File is truncated to zero length.\n");
    }

    close(fd);
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 12.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
File descriptor: 3
File opened in read-write mode.
*/
