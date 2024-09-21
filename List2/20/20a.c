/*
============================================================================
Name : 20a.c
Author : Gnanendhar Reddy
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(void) {
    int fd = open("fifo", O_RDONLY | O_CREAT, 0666);
    char buffer[100];
    int size = read(fd, buffer, 100);
    printf("%s\n", buffer);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/20$ cc 20a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/20$ ./a.out
Hi Parent!
*/
