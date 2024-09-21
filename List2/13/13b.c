/*
============================================================================
Name : 13b.c
Author : Gnanendhar Reddy
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/types.h> 
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int killStatus; // Determines success of `kill`
    pid_t pid;

    if (argc != 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);

    killStatus = kill(pid, SIGSTOP);

    if(!killStatus) 
        printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);
    else 
        perror("Error while sending signal!");
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/13$ cc 13b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/13$ ./a.out 3341
Successfully sent SIGSTOP signal to process (3341)
*/
