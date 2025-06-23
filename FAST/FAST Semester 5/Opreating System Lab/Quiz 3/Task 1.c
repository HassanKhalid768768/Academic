#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_SEATS 10
int seats[NUM_SEATS];
pthread_mutex_t lock;

void* bookTicket(void* arg) {
    int seatNumber = *((int*)arg);
    while (1) {
        pthread_mutex_lock(&lock);
        if (seats[seatNumber] == 0) {
            seats[seatNumber] = 1; // Seat is booked
            printf("Seat %d booked by customer %ld\n", seatNumber, pthread_self());
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
        // Try to book another seat
        seatNumber = (seatNumber + 1) % NUM_SEATS;
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_SEATS];
    pthread_mutex_init(&lock, NULL);

    // Set all seats as available
    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = 0;
    }

    // Create customer threads to book tickets
    for (int i = 0; i < NUM_SEATS; i++) {
        int* seatNumber = (int*)malloc(sizeof(int));
        *seatNumber = i;
        pthread_create(&threads[i], NULL, bookTicket, seatNumber);
    }

    // Join threads
    for (int i = 0; i < NUM_SEATS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
