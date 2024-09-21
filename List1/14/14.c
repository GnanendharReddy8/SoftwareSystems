/*
============================================================================
Name : 14.c
Author : Gnanendhar Reddy
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("File type: Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("File type: Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("File type: Symbolic link\n");
    } else if (S_ISCHR(mode)) {
        printf("File type: Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("File type: Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("File type: FIFO/pipe\n");
    } else if (S_ISSOCK(mode)) {
        printf("File type: Socket\n");
    } else {
        printf("File type: Unknown\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;

    if (stat(argv[1], &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    print_file_type(file_stat.st_mode);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 14.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out file
File type: Regular file
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out sample
File type: Directory
*/
