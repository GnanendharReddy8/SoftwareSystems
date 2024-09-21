/*
============================================================================
Name : 8d.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM: Alarm signal\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    
    printf("Setting alarm for 5 seconds\n");
    alarm(5);  // Set alarm for 5 seconds

    pause();  // Wait for a signal

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ cc 8d.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Setting alarm for 5 seconds
Caught SIGALRM: Alarm signal
*/
