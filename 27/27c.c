/*
============================================================================
Name : 27c.c
Author : Gnanendhar Reddy
Description : Write a program to execute ls -Rl by the following system calls
c. execle
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-Rl", (char *)NULL);
    perror("execlp failed");
    return 1;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ cc 27c.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ ./a.out
.:
total 36
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1250 Aug 31 10:24 27a.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1078 Aug 31 10:27 27b.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   451 Aug 31 09:54 27c.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   478 Aug 31 10:01 27d.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   476 Aug 31 10:05 27e.c
-rwxrwxr-x 1 gnanendhar-reddy gnanendhar-reddy 15992 Aug 31 10:28 a.out
*/
