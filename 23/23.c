/*
============================================================================
Name : 23.c
Author : Gnanendhar Reddy
Description : Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Child not created");
        return 1;
    }

    if (pid == 0) {
        printf("Child process is terminating.\n");
        exit(0);
    } else {
        printf("Parent process creating child process.\n");
        printf("Parent process is sleeping for 10 seconds...\n");
        sleep(10);

        printf("Parent process is now calling wait().\n");
        wait(NULL);

        printf("Now parent process reaped the Zombie process\n");
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 23.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Parent process creating child process.
Parent process is sleeping for 10 seconds...
Child process is terminating.
Parent process is now calling wait().
Now parent process reaped the Zombie process
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ps aux | grep Z
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
gnanend+    7659  0.0  0.0  17736  2304 pts/0    S+   08:17   0:00 grep --color=auto Z
*/
