/*
============================================================================
Name : 8a.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV: Segmentation fault\n");
    exit(EXIT_FAILURE);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);
    
    // Intentionally cause segmentation fault
    int *p = NULL;
    *p = 10;  // This will cause a SIGSEGV

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ cc 8a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Caught SIGSEGV: Segmentation fault
*/
