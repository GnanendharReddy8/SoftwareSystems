/*
============================================================================
Name : 1a.c
Author : Gnanendhar Reddy
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call) 
Date: 30th Aug, 2024
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    if (symlink("1a.c", "softlink_file.txt") == -1) {
        perror("Error creating soft link");
    } else {
        printf("Soft link created successfully.\n");
    }
    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ cc 1a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ ./a.out
Soft link created successfully.
//Using shell command : ls -l softlink_file.txt
*/
