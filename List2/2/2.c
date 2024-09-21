/*
============================================================================
Name : 2.c
Author : Gnanendhar Reddy
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char* resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    printf("%-20s: Soft limit = ", resource_name);

    if (limit.rlim_cur == RLIM_INFINITY) {
        printf("Unlimited");
    } else {
        printf("%ld", limit.rlim_cur);
    }

    printf(", Hard limit = ");

    if (limit.rlim_max == RLIM_INFINITY) {
        printf("Unlimited\n");
    } else {
        printf("%ld\n", limit.rlim_max);
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data segment size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NPROC, "Number of processes");
    print_limit(RLIMIT_NOFILE, "Number of open files");
    print_limit(RLIMIT_MEMLOCK, "Locked memory");
    print_limit(RLIMIT_AS, "Address space");
    print_limit(RLIMIT_LOCKS, "File locks");
    print_limit(RLIMIT_SIGPENDING, "Pending signals");
    print_limit(RLIMIT_MSGQUEUE, "Message queue size");
    print_limit(RLIMIT_NICE, "Nice priority");
    print_limit(RLIMIT_RTPRIO, "Real-time priority");
#ifdef RLIMIT_RTTIME
    print_limit(RLIMIT_RTTIME, "Real-time timeout");
#endif

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/2$ cc 2.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/2$ ./a.out
CPU time            : Soft limit = Unlimited, Hard limit = Unlimited
File size           : Soft limit = Unlimited, Hard limit = Unlimited
Data segment size   : Soft limit = Unlimited, Hard limit = Unlimited
Stack size          : Soft limit = 8388608, Hard limit = Unlimited
Core file size      : Soft limit = 0, Hard limit = Unlimited
Resident set size   : Soft limit = Unlimited, Hard limit = Unlimited
Number of processes : Soft limit = 127095, Hard limit = 127095
Number of open files: Soft limit = 1024, Hard limit = 1048576
Locked memory       : Soft limit = 4175421440, Hard limit = 4175421440
Address space       : Soft limit = Unlimited, Hard limit = Unlimited
File locks          : Soft limit = Unlimited, Hard limit = Unlimited
Pending signals     : Soft limit = 127095, Hard limit = 127095
Message queue size  : Soft limit = 819200, Hard limit = 819200
Nice priority       : Soft limit = 0, Hard limit = 0
Real-time priority  : Soft limit = 0, Hard limit = 0
Real-time timeout   : Soft limit = Unlimited, Hard limit = Unlimited
*/
