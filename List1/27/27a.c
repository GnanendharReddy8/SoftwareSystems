/*
============================================================================
Name : 27a.c
Author : Gnanendhar Reddy
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
   printf("Output using execl system call.\n");
   if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
       perror("execl failed");
     exit(1);
   }
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ cc 27a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ ./a.out
Output using execl system call.
.:
total 44
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  5177 Aug 31 10:17 27a.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  5005 Aug 31 10:19 27b.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   451 Aug 31 09:54 27c.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   478 Aug 31 10:01 27d.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   476 Aug 31 10:05 27e.c
-rwxrwxr-x 1 gnanendhar-reddy gnanendhar-reddy 16080 Aug 31 10:20 a.out
*/
