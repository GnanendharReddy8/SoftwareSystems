/*
============================================================================
Name : 24.c
Author : Gnanendhar Reddy
Description : Write a program to create an orphan process.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        sleep(1);  // Give the parent time to terminate
        printf("Child process (PID: %d) initial Parent PID: %d\n", getpid(), getppid());

        sleep(10);  // Ensure enough time for reparenting to init (PID 1)
        printf("Child process (PID: %d) after reparenting, Parent PID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process (PID: %d) is terminating.\n", getpid());
        exit(0);  // Parent process terminates, leaving the child process orphaned
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 24.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Parent process (PID: 7693) is terminating.
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ Child process (PID: 7694) initial Parent PID: 1487
Child process (PID: 7694) after reparenting, Parent PID: 1487
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ps -o ppid= -p 1487
      1
*/
