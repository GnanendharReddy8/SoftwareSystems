/*
============================================================================
Name : 20b.c
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

int main() {
    int fd = open("fifo", O_WRONLY | O_CREAT, 0666);
    char buffer[100];
    printf("Enter a message for the parent: ");
    fgets(buffer, sizeof(buffer), stdin);
    write(fd, buffer, sizeof(buffer));
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/20$ cc 20b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/20$ ./a.out
Enter a message for the parent: Hi Parent!
*/
