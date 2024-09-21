/*
============================================================================
Name : 17ii.c
Author : Gnanendhar Reddy
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 30th Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void lock_file(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to set write lock");
        exit(EXIT_FAILURE);
    }
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release write lock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    lock_file(fd);

    int ticket_number;
    if (read(fd, &ticket_number, sizeof(ticket_number)) == -1) {
        perror("Failed to read from file");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    ticket_number++;  // Increment the ticket number
    printf("New ticket number: %d\n", ticket_number);

    lseek(fd, 0, SEEK_SET);  // Reset file pointer to the beginning
    if (write(fd, &ticket_number, sizeof(ticket_number)) == -1) {
        perror("Failed to write to file");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    unlock_file(fd);
    close(fd);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 17ii.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
New ticket number: 1001
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
New ticket number: 1002
*/
