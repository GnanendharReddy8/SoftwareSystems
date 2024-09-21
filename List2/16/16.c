/*
============================================================================
Name : 16.c
Author : Gnanendhar Reddy
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include <sys/wait.h>

int main() {
    int p[2], r[2];
    pipe(p);
    pipe(r);
    pid_t pid = fork();
    if (!pid) {
        close(p[1]);
        close(r[0]);
        char buffer[1024];
        int n = read(p[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Child received: %s\n", buffer);
        }
        buffer[0]='\0';
        printf("Enter a message for the parent: ");
        fgets(buffer, sizeof(buffer), stdin);
        n=write(r[1], buffer, strlen(buffer));
        close(p[0]);
        close(r[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(p[0]);
        close(r[1]);
        char buffer[1024];
        printf("Enter a message for the child: ");
        fgets(buffer, sizeof(buffer), stdin);
        // read(0,buffer,strlen(buffer));
        int n = write(p[1], buffer, strlen(buffer));
        buffer[0]='\0';
        n=read(r[0], buffer, sizeof(buffer));
        if (n > 0) {
            printf("Parent received: %s\n", buffer);
        }
        close(p[1]);
        wait(NULL);
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/16$ cc 16.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/16$ ./a.out
Enter a message for the child: Hi Child Process!
Child received: Hi Child Process!
�V
Enter a message for the parent: Hello Parent process!
Parent received: Hello Parent process!
*/
