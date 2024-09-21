/*
============================================================================
Name : 21b.c
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
    int fd1 = open("fifo1", O_RDWR | O_CREAT, 0666);
    int fd2 = open("fifo2", O_RDWR | O_CREAT, 0666);
    char buffer_write[1024] ;
    char buffer_read[1024] ;
    printf("Enter message : ");
    scanf("%s", buffer_write);
    write(fd1, buffer_write, 1024);
    read(fd2, buffer_read, 1024);
    printf("%s\n", buffer_read);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ cc 21b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ ./a.out
Enter message : GoodAfterNoon!
HappyMorning!
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ cc 21b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/21$ ./a.out
Enter message : Bye!
GoodEvening!
*/
