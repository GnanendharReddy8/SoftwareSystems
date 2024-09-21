/*
============================================================================
Name : 18.c
Author : Gnanendhar Reddy
Description : Write a program to perform Record locking.
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    char data[80];
};

int main() {
    int fd = open("records.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    struct record records[3] = {
        {1, "Record 1: Initial data"},
        {2, "Record 2: Initial data"},
        {3, "Record 3: Initial data"}
    };

    if (write(fd, records, sizeof(records)) == -1) {
        perror("Failed to write records to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Three records initialized in the file.\n");
    close(fd);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 18.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Three records initialized in the file.
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cat records.txt
Record 1: Initial dataRecord 2: Initial dataRecord 3: Initial data
*/
