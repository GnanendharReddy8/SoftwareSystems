/*
============================================================================
Name : 13a.c
Author : Gnanendhar Reddy
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21st Sep, 2024.
============================================================================
*/
#include <signal.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void customHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines success of `signal`
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    signalStatus = signal(SIGSTOP, customHandler);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");

    printf("Putting the process to sleep for 15s\n");
    sleep(15);
}

/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/13$ cc 13a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/13$ ./a.out
Process ID: 3585
Error while catching signal!: Invalid argument
Putting the process to sleep for 15s
*/
