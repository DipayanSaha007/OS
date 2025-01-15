#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void *num) {
    int id = *(int *)num;
    
    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 3);

        pthread_mutex_lock(&forks[id]);
        pthread_mutex_lock(&forks[(id + 1) % NUM_PHILOSOPHERS]);

        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3);

        pthread_mutex_unlock(&forks[id]); 
        pthread_mutex_unlock(&forks[(id + 1) % NUM_PHILOSOPHERS]); 
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopherIds[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIds[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIds[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}

