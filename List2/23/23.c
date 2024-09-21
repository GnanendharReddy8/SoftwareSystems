/*
============================================================================
Name : 23.c
Author : Gnanendhar Reddy
Description : 23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main() {
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("The maximum number of files can be opened within a process is %ld.\n", OPEN_MAX);
    printf("The size of a pipe (circular buffer) is %ld bytes.\n", PIPE_BUF);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/23$ cc 23.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/23$ ./a.out
The maximum number of files can be opened within a process is 1024.
The size of a pipe (circular buffer) is 4096 bytes.
*/
