/*
============================================================================
Name : 9.c
Author : Gnanendhar Reddy
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_file_info(const char *filename) {
    struct stat file_stat;

    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("Inode: %lu\n", (unsigned long)file_stat.st_ino);

    printf("Number of hard links: %lu\n", (unsigned long)file_stat.st_nlink);

    printf("UID: %u\n", file_stat.st_uid);
    
    printf("GID: %u\n", file_stat.st_gid);

    printf("Size: %lld bytes\n", (long long)file_stat.st_size);
 
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);

    printf("Number of blocks: %lld\n", (long long)file_stat.st_blocks);

    printf("Time of last access: %s", ctime(&file_stat.st_atime));
  
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));

    printf("Time of last status change: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_file_info(argv[1]);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 9.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out file
Inode: 1583397
Number of hard links: 1
UID: 1000
GID: 1000
Size: 21 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Fri Aug 30 15:50:12 2024
Time of last modification: Fri Aug 30 15:50:09 2024
Time of last status change: Fri Aug 30 15:50:09 2024
*/
