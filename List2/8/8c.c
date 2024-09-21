/*
============================================================================
Name : 8c.c
Author : Gnanendhar Reddy
Description : 8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE: Floating point exception\n");
    exit(EXIT_FAILURE);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    
    // Intentionally cause a floating-point exception (division by zero)
    int a = 1 / 0;  // This will cause a SIGFPE

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ cc 8c.c
8c.c: In function ‘main’:
8c.c:14:15: warning: division by zero [-Wdiv-by-zero]
   14 |     int a = 1 / 0;  // This will cause a SIGFPE
      |               ^
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/8$ ./a.out
Caught SIGFPE: Floating point exception
*/
