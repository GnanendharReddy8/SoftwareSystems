/*
============================================================================
Name : 10b.c
Author : Gnanendhar Reddy
Description : 10. Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 21st Sep, 2024.
============================================================================
*/
#include <signal.h>
#include <stdio.h> 
#include <unistd.h>

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/10$ cc 10b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/10$ ./a.out
^CCaught signal SIGINT (2)
*/
