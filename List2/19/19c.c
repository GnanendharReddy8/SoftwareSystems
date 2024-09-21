/*
============================================================================
Name : 19c.c
Author : Gnanendhar Reddy
Description : 19. Create a FIFO file by
c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()
{
	if(!fork())
	{
		printf("\nUsing mkfifo:\n");
		execlp("strace","strace","-c","mkfifo","fifo1",NULL);
	}
	else
	{
		wait(0);
		printf("\nUsing mknod:\n");
		execlp("strace","strace","-c","mknod","fifo2","p",NULL);
	}
	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ cc 19c.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/19$ ./a.out

Using mkfifo:
mkfifo: cannot create fifo 'fifo1': File exists
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 40.81    0.000384          20        19           mmap
 23.49    0.000221           7        31        23 openat
  6.06    0.000057          11         5           mprotect
  5.95    0.000056           5        10           close
  5.84    0.000055           7         7           read
  4.36    0.000041           5         8           newfstatat
  2.55    0.000024           6         4           write
  2.55    0.000024          12         2         2 statfs
  2.23    0.000021          21         1           munmap
  1.28    0.000012           4         3           brk
  0.96    0.000009           9         1         1 mknodat
  0.64    0.000006           3         2         2 access
  0.64    0.000006           3         2         1 arch_prctl
  0.53    0.000005           5         1           set_tid_address
  0.53    0.000005           5         1           set_robust_list
  0.53    0.000005           5         1           prlimit64
  0.53    0.000005           5         1           getrandom
  0.53    0.000005           5         1           rseq
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000941           9       103        29 total

Using mknod:
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         5           read
  0.00    0.000000           0         8           close
  0.00    0.000000           0        18           mmap
  0.00    0.000000           0         5           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         2         2 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         6           openat
  0.00    0.000000           0         1           mknodat
  0.00    0.000000           0         6           newfstatat
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
  0.00    0.000000           0         1           rseq
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000           0        67         5 total
*/
