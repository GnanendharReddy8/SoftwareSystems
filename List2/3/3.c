/*
============================================================================
Name : 3.c
Author : Gnanendhar Reddy
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    // Get the current limit for the number of open files
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("Current limits:\n");
    printf("Soft limit: %ld\n", limit.rlim_cur);
    printf("Hard limit: %ld\n", limit.rlim_max);

    // Set new soft and hard limits
    limit.rlim_cur = 512;  // Set the new soft limit
    limit.rlim_max = 512;  // Set the new hard limit

    if (setrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    // Get the updated limit to verify
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("\nUpdated limits:\n");
    printf("Soft limit: %ld\n", limit.rlim_cur);
    printf("Hard limit: %ld\n", limit.rlim_max);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/3$ cc 3.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/3$ ./a.out
Current limits:
Soft limit: 1024
Hard limit: 1048576

Updated limits:
Soft limit: 512
Hard limit: 512
*/
