/*
============================================================================
Name : 11.c
Author : Gnanendhar Reddy
Description : 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 21st Sep, 2024.
============================================================================
*/
#include <signal.h> // Import for `sigaction`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;

    // Ignore SIGINT
    printf("Ignoring SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);


    // Provide custom handler
    printf("Handling SIGINT for 5 seconds!\n");
    action.sa_handler = signalHandler;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);

    // Setting default handler
    printf("Default action for SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_DFL;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/11$ cc 11.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/11$ ./a.out
Ignoring SIGINT for 5 seconds!
Handling SIGINT for 5 seconds!
Default action for SIGINT for 5 seconds!
*/
