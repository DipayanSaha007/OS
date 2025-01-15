#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "psem.h"

#define FILE_NAME "shared_file.txt"
#define SEM_RESOURCE "/resource_semaphore"

int main() {
    psem_t resource_sem;

    if (!psem_init(&resource_sem, SEM_RESOURCE, 1)) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    int i = 0; 
    while (1) {
        // Wait for the semaphore
        if (!psem_wait(&resource_sem)) {
            perror("Failed to lock semaphore");
            exit(EXIT_FAILURE);
        }

        // Write to the file
        FILE *file = fopen(FILE_NAME, "a");
        if (!file) {
            perror("File opening failed");
            psem_post(&resource_sem);
            exit(EXIT_FAILURE);
        }

        fprintf(file, "%d ", i);
        printf("Writer: Writing '%d' to the file\n", i);
        fclose(file);
        i++;

        // Release the semaphore
        if (!psem_post(&resource_sem)) {
            perror("Failed to unlock semaphore");
            exit(EXIT_FAILURE);
        }

        sleep(2); 
    }

    return 0;
}

