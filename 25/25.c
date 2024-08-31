/*
============================================================================
Name : 25.c
Author : Gnanendhar Reddy
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            perror("fork");
            exit(1);
        } else if (pids[i] == 0) {
            printf("Child %d with PID %d\n", i + 1, getpid());
	    sleep(2);
            exit(0);
        }
    }

    int status;
    pid_t target_pid = pids[1];

    printf("Waiting for child with PID %d\n", target_pid);
    pid_t waited_pid = waitpid(target_pid, &status, 0);

    if (waited_pid == -1) {
        perror("Error while waitpid");
        exit(1);
    } else
    {
        printf("Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 25.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Child 1 with PID 7736
Waiting for child with PID 7737
Child 2 with PID 7737
Child 3 with PID 7738
Child with PID 7737 exited with status 0
*/
