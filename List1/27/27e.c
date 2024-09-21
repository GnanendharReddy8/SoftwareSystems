/*
============================================================================
Name : 27e.c
Author : Gnanendhar Reddy
Description : Write a program to execute ls -Rl by the following system calls
e. execvp
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
  
    execvp("ls", args);
  
    perror("execvp failed");
    return 1;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ cc 27e.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/27$ ./a.out
.:
total 36
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1250 Aug 31 10:24 27a.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1078 Aug 31 10:27 27b.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1078 Aug 31 10:28 27c.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy  1105 Aug 31 10:30 27d.c
-rw-rw-r-- 1 gnanendhar-reddy gnanendhar-reddy   476 Aug 31 10:05 27e.c
-rwxrwxr-x 1 gnanendhar-reddy gnanendhar-reddy 16048 Aug 31 10:30 a.out
*/
