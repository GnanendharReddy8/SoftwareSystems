/*
============================================================================
Name : 5.c
Author : Gnanendhar Reddy
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 30th Aug, 2024
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1, fd2, fd3, fd4, fd5;

    while (1) {
        fd1 = creat("file1.txt", 0644);
        fd2 = creat("file2.txt", 0644);
        fd3 = creat("file3.txt", 0644);
        fd4 = creat("file4.txt", 0644);
        fd5 = creat("file5.txt", 0644);

        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        close(fd5);
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 5.c -o output
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./output &
[3] 5265
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ls -l /proc/5265/fd
total 0
lrwx------ 1 gnanendhar-reddy gnanendhar-reddy 64 Aug 30 15:20 0 -> /dev/pts/0
lrwx------ 1 gnanendhar-reddy gnanendhar-reddy 64 Aug 30 15:20 1 -> /dev/pts/0
lrwx------ 1 gnanendhar-reddy gnanendhar-reddy 64 Aug 30 15:20 2 -> /dev/pts/0
*/
