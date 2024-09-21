/*
============================================================================
Name : 1c.c
Author : Gnanendhar Reddy
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void timer_handler(int signum) {
    printf("Profiling timer expired\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/1$ cc 1c.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/1$ ./a.out
Profiling timer expired
*/
