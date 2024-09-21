/*
============================================================================
Name : 10a.c
Author : Gnanendhar Reddy
Description : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 21st Sep, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGSEGV (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;
    char *a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGSEGV, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        raise(SIGSEGV);
    }
}

/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/10$ cc 10a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/10$ ./a.out
Caught signal SIGSEGV (11)
*/
