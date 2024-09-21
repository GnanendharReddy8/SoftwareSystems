/*
============================================================================
Name : 19b.c
Author : Gnanendhar Reddy
Description : 19. Create a FIFO file by
b. mkfifo command
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
	execlp("mkfifo","mkfifo","fifo1",NULL);

	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ./a.out
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ls
19a.c  19b.c  a.out  fifo1
*/
