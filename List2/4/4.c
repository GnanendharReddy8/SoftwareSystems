/*
============================================================================
Name : 4.c
Author : Gnanendhar Reddy
Description : 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

// Function to read Time Stamp Counter (TSC)
unsigned long long read_tsc() {
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    int i;

    // Read TSC before the calls
    start = read_tsc();

    // Perform 100 getppid() system calls
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Read TSC after the calls
    end = read_tsc();

    // Calculate and print the total cycles taken
    printf("Time taken to execute 100 getppid() calls: %llu CPU cycles\n", end - start);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/4$ cc 4.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/4$ ./a.out
Time taken to execute 100 getppid() calls: 187884 CPU cycles
*/
