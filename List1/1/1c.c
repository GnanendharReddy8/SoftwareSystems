/*
============================================================================
Name : 1c.c
Author : Gnanendhar Reddy
Description : 1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call) 
Date: 30th Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *fifo_file = "my_fifo";

    // Create a FIFO file
    if (mkfifo(fifo_file, 0666) == -1) {
        perror("Error creating FIFO");
    } else {
        printf("FIFO created successfully.\n");
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ cc 1c.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp/1$ ./a.out
FIFO created successfully.
//Using shell command : mkfifo fifo_file
*/
