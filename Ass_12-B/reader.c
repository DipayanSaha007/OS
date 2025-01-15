#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "psem.h"

#define FILE_NAME "shared_file.txt"
#define SEM_NAME "/file_semaphore"

int main() {
    psem_t semaphore;

    if (!psem_init(&semaphore, SEM_NAME, 1)) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Wait on semaphore
        if (!psem_wait(&semaphore)) {
            perror("Failed to lock semaphore");
            exit(EXIT_FAILURE);
        }

        // Read from the file
        FILE *file = fopen(FILE_NAME, "r");
        if (!file) {
            perror("File opening failed");
            psem_post(&semaphore);
            exit(EXIT_FAILURE);
        }

        char buffer[256];
        printf("Reader: Reading Contents of the file: ");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
        printf("\n");

        // Release semaphore
        if (!psem_post(&semaphore)) {
            perror("Failed to unlock semaphore");
            exit(EXIT_FAILURE);
        }
        
        sleep(2);
    }

    return 0;
}

