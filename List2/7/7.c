/*
============================================================================
Name : 7.c
Author : Gnanendhar Reddy
Description : 7. Write a simple program to print the created thread ids.
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg);
    printf("Thread %d with ID %lu is running\n", thread_num, pthread_self());
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
        printf("Thread %d with ID %lu has finished execution\n", i + 1, threads[i]);
    }

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/7$ cc 7.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/7$ ./a.out
Thread 1 with ID 140367705929408 is running
Thread 2 with ID 140367697536704 is running
Thread 3 with ID 140367689144000 is running
Thread 1 with ID 140367705929408 has finished execution
Thread 2 with ID 140367697536704 has finished execution
Thread 3 with ID 140367689144000 has finished execution
*/
