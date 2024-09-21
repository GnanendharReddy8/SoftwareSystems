/*
============================================================================
Name : 8b.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT: Interrupt signal\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    
    printf("Press Ctrl + C to trigger SIGINT\n");
    while (1);  // Infinite loop to keep the program running

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Press Ctrl + C to trigger SIGINT
^CCaught SIGINT: Interrupt signal
*/
