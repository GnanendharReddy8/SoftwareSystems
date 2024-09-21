/*
============================================================================
Name : 6.c
Author : Gnanendhar Reddy
Description : 6. Write a simple program to create three threads.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg);
    printf("Thread %d is running\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_args[3];
    int i;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Join 3 threads
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have finished execution\n");

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/6$ cc 6.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/6$ ./a.out
Thread 1 is running
Thread 2 is running
Thread 3 is running
All threads have finished execution
*/
