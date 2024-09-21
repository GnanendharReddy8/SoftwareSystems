/*
============================================================================
Name : 16.c
Author : Gnanendhar Reddy
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{

  int fd = open("test.txt",O_WRONLY|O_APPEND);
  if(fd == -1)
  {
    printf("File cannot be opened \n");
    exit(0);
  }
  struct flock locking;
  locking.l_type = F_WRLCK;
  locking.l_whence = SEEK_SET;
  locking.l_start = 0;
  locking.l_len = 0;
  
  
  int stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock for writing so exiting the program \n");
    exit(0);
  }

  char *buffer = "This to written by locking the file \n";
  write(fd,buffer,37);
  
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
  
  fd = open("test.txt",O_RDONLY);
  locking.l_type = F_RDLCK;
  
  stat = fcntl(fd,F_SETLK,&locking);
  if(stat == -1)
  {
    printf("Cannot obtained the lock  for reading file so exiting the program  \n");
    exit(0);
  }
  
  char ss[1024];
  
  while(read(fd,ss,1))
  {
    printf("%s",ss);
  }
  locking.l_type = F_UNLCK;
  fcntl(fd,F_SETLK,&locking);
  
  close(fd);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
This is a test file
This to written by locking the file 
This to written by locking the file 
This to written by locking the file 
This to written by locking the file 
*/
