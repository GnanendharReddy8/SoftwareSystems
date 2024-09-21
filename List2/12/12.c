/*
============================================================================
Name : 12.c
Author : Gnanendhar Reddy
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process
Date: 21st Sep, 2024.
============================================================================
*/
#include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>    // Import for `kill`
#include <unistd.h>    // Import for `fork`, `sleep`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent process!\n");
            sleep(10);
            printf("Child process is now exiting!\n");
        }
        else
            perror("Error while killing parent process!");
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/12$ cc 12.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/12$ ./a.out
Child PID: 3547
Parent PID: 3546
Successfully killed parent process!
Killed
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/12$ Child process is now exiting!
*/
