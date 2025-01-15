#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "psem.h"

#define NUM_PHILOSOPHERS 5
#define THINKING_TIME 2
#define EATING_TIME 2

void philosopher(int id) {
    char left_chopstick_name[20], right_chopstick_name[20];
    psem_t left_chopstick, right_chopstick;

    // Generate unique names for semaphores
    snprintf(left_chopstick_name, sizeof(left_chopstick_name), "/chopstick_%d", id);
    snprintf(right_chopstick_name, sizeof(right_chopstick_name), "/chopstick_%d", (id + 1) % NUM_PHILOSOPHERS);

    // Link to existing semaphores
    psem_init(&left_chopstick, left_chopstick_name, -1); // -1 links to existing semaphore
    psem_init(&right_chopstick, right_chopstick_name, -1);

    for (int i = 0; i < 3; i++) { // Run multiple dining cycles for simulation
        printf("Philosopher %d is thinking.\n", id);
        sleep(THINKING_TIME);

        // Pick up chopsticks
        if (id % 2 == 0) { // Even philosophers pick up left chopstick first
            psem_wait(&left_chopstick);
            printf("Philosopher %d picked up left chopstick %d.\n", id, id);
            psem_wait(&right_chopstick);
            printf("Philosopher %d picked up right chopstick %d.\n", id, (id + 1) % NUM_PHILOSOPHERS);
        } else { // Odd philosophers pick up right chopstick first
            psem_wait(&right_chopstick);
            printf("Philosopher %d picked up right chopstick %d.\n", id, (id + 1) % NUM_PHILOSOPHERS);
            psem_wait(&left_chopstick);
            printf("Philosopher %d picked up left chopstick %d.\n", id, id);
        }

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(EATING_TIME);

        // Put down chopsticks
        psem_post(&left_chopstick);
        printf("Philosopher %d put down left chopstick %d.\n", id, id);
        psem_post(&right_chopstick);
        printf("Philosopher %d put down right chopstick %d.\n", id, (id + 1) % NUM_PHILOSOPHERS);

        printf("Philosopher %d is done eating and starts thinking again.\n", id);
    }

    // Close semaphores
    sem_close(left_chopstick.semp);
    sem_close(right_chopstick.semp);

    exit(0); // End the philosopher process
}

int main() {
    pid_t pids[NUM_PHILOSOPHERS];
    psem_t chopsticks[NUM_PHILOSOPHERS];

    // Initialize semaphores for chopsticks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        char name[20];
        snprintf(name, sizeof(name), "/chopstick_%d", i);
        if (!psem_init(&chopsticks[i], name, 1)) { // Initialize each chopstick as a semaphore
            fprintf(stderr, "Failed to initialize semaphore for chopstick %d.\n", i);
            return 1;
        }
    }

    // Create philosopher processes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        if ((pids[i] = fork()) == 0) { // Child process
            philosopher(i);
        }
    }

    // Wait for all philosopher processes to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Cleanup semaphores
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        char name[20];
        snprintf(name, sizeof(name), "/chopstick_%d", i);
        psem_destroy(&chopsticks[i]);
    }

    printf("Dining Philosopher simulation complete.\n");
    return 0;
}

