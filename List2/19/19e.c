/*
============================================================================
Name : 19e.c
Author : Gnanendhar Reddy
Description : 19. Create a FIFO file by
e. mkfifo library function
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int result = mkfifo("f1.fifo",S_IRWXU);
	if(result < 0)
	{
		perror("mkfifo");
		exit(1);
	}
	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ cc 19e.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ./a.out
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ls
19a.c  19b.c  19c.c  19d.c  19e.c  a.out  f1.fifo  fifo1  fifo2  fifo3
*/
