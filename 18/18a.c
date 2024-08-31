/*
============================================================================
Name : 18a.c
Author : Gnanendhar Reddy
Description : Write a program to perform Record locking.
a. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct record {
    int id;
    char data[80];
};

void lock_record(int fd, int record_num, short lock_type) {
    struct flock lock;
    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_num - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to set lock");
        exit(EXIT_FAILURE);
    }
}

void unlock_record(int fd, int record_num) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_num - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to unlock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open("records.txt", O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int record_num = 2;  // Record number to lock and modify
    struct record rec;

    // Implement a write lock on the specific record
    lock_record(fd, record_num, F_WRLCK);
    printf("Write lock set on record %d\n", record_num);

    // Read the record
    lseek(fd, (record_num - 1) * sizeof(struct record), SEEK_SET);
    if (read(fd, &rec, sizeof(rec)) == -1) {
        perror("Failed to read record");
        unlock_record(fd, record_num);
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Modify the record
    snprintf(rec.data, sizeof(rec.data), "Record %d: Updated data", record_num);

    // Write the modified record back
    lseek(fd, (record_num - 1) * sizeof(struct record), SEEK_SET);
    if (write(fd, &rec, sizeof(rec)) == -1) {
        perror("Failed to write record");
        unlock_record(fd, record_num);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Record %d updated successfully.\n", record_num);

    // Unlock the record
    unlock_record(fd, record_num);
    printf("Write lock released on record %d\n", record_num);

    close(fd);
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 18a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Write lock set on record 2
Record 2 updated successfully.
Write lock released on record 2
*/
