/*
============================================================================
Name : 8g.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/time.h> 
#include <signal.h>  
#include <unistd.h> 
#include <stdio.h> 

void callback()
{
    printf("Signal SIGPROF has been caught!\n");
    _exit(0);
}

void main()
{
    int timerStatus; 
    __sighandler_t signalStatus;

    struct itimerval timer;

    // Generate signal after 1s
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    // Catch the SIGALRM signal
    signalStatus = signal(SIGPROF, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while(1);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ cc 8g.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Signal SIGPROF has been caught!
*/
