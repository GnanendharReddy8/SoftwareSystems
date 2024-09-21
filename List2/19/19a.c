/*
============================================================================
Name : 19a.c
Author : Gnanendhar Reddy
Description : 19. Create a FIFO file by
a. mknod command
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
        execlp("mknod","mknod","fifo2","p",NULL);

        return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ cc 19a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ./a.out
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ls
19a.c  a.out  fifo2
*/
