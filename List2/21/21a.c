/*
============================================================================
Name : 21a.c
Author : Gnanendhar Reddy
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communication.
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
    int fd1 = open("fifo1",O_RDWR | O_CREAT, 0666);
    int fd2 = open("fifo2",O_RDWR | O_CREAT, 0666);
    char buffer_read[1024] ;
    char buffer_write[1024];
    int size = read(fd1, buffer_read, 1024);
    printf("%s\n", buffer_read);
    printf("Enter message : ");
    scanf("%s", buffer_write);
    write(fd2, buffer_write, 1024);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ cc 21a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ ./a.out
GoodAfterNoon!
Enter message : GoodEvening!
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ cc 21a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ ./a.out
Bye!
Enter message : 
*/
