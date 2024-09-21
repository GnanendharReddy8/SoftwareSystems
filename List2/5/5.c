/*
============================================================================
Name : 5.c
Author : Gnanendhar Reddy
Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <limits.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions.
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("a. Maximum length of arguments to exec: %ld bytes\n", arg_max);

    // b. Maximum number of simultaneous processes per user id.
    long max_procs = sysconf(_SC_CHILD_MAX);
    printf("b. Maximum number of simultaneous processes per user: %ld\n", max_procs);

    // c. Number of clock ticks (jiffy) per second.
    long clk_tck = sysconf(_SC_CLK_TCK);
    printf("c. Number of clock ticks per second: %ld\n", clk_tck);

    // d. Maximum number of open files.
    long max_open_files = sysconf(_SC_OPEN_MAX);
    printf("d. Maximum number of open files: %ld\n", max_open_files);

    // e. Size of a page.
    long page_size = sysconf(_SC_PAGESIZE);
    printf("e. Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory.
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("f. Total number of pages in physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory.
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("g. Number of available pages in physical memory: %ld\n", avail_pages);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/5$ cc 5.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/5$ ./a.out
a. Maximum length of arguments to exec: 2097152 bytes
b. Maximum number of simultaneous processes per user: 127095
c. Number of clock ticks per second: 100
d. Maximum number of open files: 1024
e. Size of a page: 4096 bytes
f. Total number of pages in physical memory: 8155123
g. Number of available pages in physical memory: 7343514
*/
