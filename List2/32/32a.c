/*
============================================================================
Name : 32a.c
Author : Gnanendhar Reddy
Description : 32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 21st Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TICKETS 10

int ticket_counter = 1;
sem_t mutex;

void* sellTicket(void* arg) {

    while (1) {
        sem_wait(&mutex); // Wait for the semaphore
        if (ticket_counter <= NUM_TICKETS) {
            printf("Ticket %d sold.\n", ticket_counter);
            ticket_counter++;
        }
        sem_post(&mutex); // Release the semaphore

        if (ticket_counter > NUM_TICKETS) break;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t seller1, seller2;

    sem_init(&mutex, 0, 1);

    pthread_create(&seller1, NULL, sellTicket, NULL);
    pthread_create(&seller2, NULL, sellTicket, NULL);

    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);

    sem_destroy(&mutex);

    return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ cc 32a.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ ./a.out
Ticket 1 sold.
Ticket 2 sold.
Ticket 3 sold.
Ticket 4 sold.
Ticket 5 sold.
Ticket 6 sold.
Ticket 7 sold.
Ticket 8 sold.
Ticket 9 sold.
Ticket 10 sold.
*/
