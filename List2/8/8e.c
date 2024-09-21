/*
============================================================================
Name : 8e.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM: Alarm signal using setitimer\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, sigalrm_handler);

    // Set timer to go off in 3 seconds
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No repeating
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    pause();  // Wait for the signal

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ cc 8e.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Caught SIGALRM: Alarm signal using setitimer
*/
