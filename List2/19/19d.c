/*
============================================================================
Name : 19d.c
Author : Gnanendhar Reddy
Description : 19. Create a FIFO file by
d. mknod system call
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
	int result = mknod("fifo3", S_IRUSR | S_IWUSR | S_IFIFO, 0);
	if(result < 0)
	{
		perror("mknod");
		exit(1);
	}
	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ cc 19d.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ./a.out
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ls
19a.c  19b.c  19c.c  19d.c  19e.c  a.out  f1.fifo  fifo1  fifo2  fifo3
*/
