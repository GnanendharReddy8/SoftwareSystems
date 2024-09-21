/*
============================================================================
Name : 13.c
Author : Gnanendhar Reddy
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on stdin for 10 seconds...\n");

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select() failed");
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        printf("No input available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Input is available on stdin.\n");
        }
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 13.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Waiting for input on stdin for 10 seconds...
No input available within 10 seconds.
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Waiting for input on stdin for 10 seconds...
abc
Input is available on stdin.
*/
