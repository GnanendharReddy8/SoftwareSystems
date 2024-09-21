/*
============================================================================
Name : 19.c
Author : Gnanendhar Reddy
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    pid_t pid;

    start = rdtsc();

    pid = getpid();

    end = rdtsc();

    printf("Time taken by getpid(): %llu CPU cycles\n", end - start);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 19.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Time taken by getpid(): 17222 CPU cycles
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
Time taken by getpid(): 14998 CPU cycles
*/
