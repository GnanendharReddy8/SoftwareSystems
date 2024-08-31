/*
============================================================================
Name : 26a.c
Author : Gnanendhar Reddy
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *program = "./a.out"; // Path to the executable program
    char *arg1 = "Gnani";        // Argument to pass to the program

    char *args[] = { program, arg1, NULL };

    // Execute the program
    execvp(program, args);

    // If execvp returns, it means there was an error
    perror("execvp failed");
    return 1;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc sample_prog.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc -o 26 26.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./26
Hello, Gnani!
*/
