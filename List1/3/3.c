/*
============================================================================
Name : 3.c
Author : Gnanendhar Reddy
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 30th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = creat("example.txt", 0644);

    if (fd == -1) {
        perror("File creation failed");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    close(fd);

    return 0;
}

/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 3.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
File descriptor: 3
*/
