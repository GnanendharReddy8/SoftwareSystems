/*
============================================================================
Name : 1b.c
Author : Gnanendhar Reddy
Description : 1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 30th Aug, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *original_file = "original_file.txt";
   
    const char *hardlink_file = "hardlink_file.txt";

    // Create a hard link
    if (link(original_file, hardlink_file) == -1) {
        perror("Error creating hard link");
    } else {
        printf("Hard link created successfully.\n");
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ cc 1b.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ ./a.out
Hard link created successfully.
//Using shell command : ls -li original_file.txt hardlink_file.txt
*/
