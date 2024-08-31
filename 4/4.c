/*
============================================================================
Name : 4.c
Author : Gnanendhar Reddy
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 30th Aug, 2024
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("Test4.txt", O_RDWR | O_EXCL);

    if (fd == -1) {
        perror("File open failed");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    close(fd);

    return 0;
}

/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 4.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
File descriptor: 3
*/
