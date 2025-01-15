#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 3
#define READ_TIME 1
#define WRITE_TIME 2

pthread_mutex_t readWriteLock;
pthread_mutex_t mutex;
int readCount = 0;
int data = 0;

void *reader(void *id) {
    int readerId = *(int *)id;

    while (1) {
        pthread_mutex_lock(&mutex);
        readCount++;
        if (readCount == 1) {
            pthread_mutex_lock(&readWriteLock);
        }
        pthread_mutex_unlock(&mutex);

        printf("Reader %d: reading data = %d\n", readerId, data);
        sleep(READ_TIME);

        pthread_mutex_lock(&mutex);
        readCount--;
        if (readCount == 0) {
            pthread_mutex_unlock(&readWriteLock);
        }
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

void *writer(void *id) {
    int writerId = *(int *)id;

    while (1) {
        pthread_mutex_lock(&readWriteLock); 

        data++;
        printf("Writer %d: writing data = %d\n", writerId, data);
        sleep(WRITE_TIME);

        pthread_mutex_unlock(&readWriteLock);

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];

    pthread_mutex_init(&readWriteLock, NULL);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIds[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIds[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&readWriteLock);
    pthread_mutex_destroy(&mutex);

    return 0;
}

