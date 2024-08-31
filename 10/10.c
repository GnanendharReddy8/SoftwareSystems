/*
============================================================================
Name : 10.c
Author : Gnanendhar Reddy
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "example_file.txt"
#define BUFFER_SIZE 10

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;

    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Data to write
    const char *data1 = "ABCDEFGHIJ";
    const char *data2 = "1234567890\n";

    // Write 10 bytes to the file
    bytes_written = write(fd, data1, BUFFER_SIZE);
    if (bytes_written != BUFFER_SIZE) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer by 10 bytes
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t) -1) {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    bytes_written = write(fd, data2, BUFFER_SIZE);
    if (bytes_written != BUFFER_SIZE) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    close(fd);
    printf("File operations completed successfully.\n");
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 10.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
File operations completed successfully.
*/
