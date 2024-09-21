/*
============================================================================
Name : 11.c
Author : Gnanendhar Reddy
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define FILE_NAME "testfile.txt"
#define BUFFER_SIZE 256

// Function to append data using a given file descriptor
void append_data(int fd, const char *data) {
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int original_fd, dup_fd, dup2_fd, fcntl_fd;
    const char *data1 = "Data appended using original file descriptor.\n";
    const char *data2 = "Data appended using dup() file descriptor.\n";
    const char *data3 = "Data appended using dup2() file descriptor.\n";
    const char *data4 = "Data appended using fcntl() file descriptor.\n";

    original_fd = open(FILE_NAME, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (original_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dup_fd = dup(original_fd);
    if (dup_fd == -1) {
        perror("dup");
        close(original_fd);
        exit(EXIT_FAILURE);
    }

    dup2_fd = dup2(original_fd, 100); // Arbitrary descriptor number (100)
    if (dup2_fd == -1) {
        perror("dup2");
        close(original_fd);
        close(dup_fd);
        exit(EXIT_FAILURE);
    }

    fcntl_fd = fcntl(original_fd, F_DUPFD, 200); // Arbitrary descriptor number (200)
    if (fcntl_fd == -1) {
        perror("fcntl");
        close(original_fd);
        close(dup_fd);
        close(dup2_fd);
        exit(EXIT_FAILURE);
    }

    append_data(original_fd, data1);
    append_data(dup_fd, data2);
    append_data(dup2_fd, data3);
    append_data(fcntl_fd, data4);

    close(original_fd);
    close(dup_fd);
    close(dup2_fd);
    close(fcntl_fd);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 11.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Data appended using original file descriptor.
Data appended using dup() file descriptor.
Data appended using dup2() file descriptor.
Data appended using fcntl() file descriptor.
*/
