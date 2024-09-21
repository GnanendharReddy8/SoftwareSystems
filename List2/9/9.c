/*
============================================================================
Name : 9.c
Author : Gnanendhar Reddy
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 21st Sep, 2024.
============================================================================
*/
#include<signal.h> 
#include <stdio.h> 
#include <unistd.h>

void sampleFunction()
{
    printf("\nSignal SIGINT has been caught!\n");
}

void main()
{
    char *a;
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    // Ignore SIGINT
    printf("Your SIGINT will be ignored for 5 seconds\n");
    signalStatus = signal(SIGINT, SIG_IGN);
    if(signalStatus == SIG_ERR)
        perror("Error while trying to ignore signal!");
    else 
        sleep(5);

    printf("SIGINT will now be caught!\n");
    signalStatus = signal(SIGINT, (void *)sampleFunction);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        sleep(5);

    printf("SIGINT will now be caught using the default handler!\n");
    signalStatus = signal(SIGINT, SIG_DFL);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        sleep(5);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/9$ cc 9.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/9$ ./a.out
Your SIGINT will be ignored for 5 seconds
SIGINT will now be caught!
SIGINT will now be caught using the default handler!
*/
