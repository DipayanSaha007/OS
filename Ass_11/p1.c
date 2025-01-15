#include <stdio.h>
#include "header.h"
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
    int shmid = shmget(1234, sizeof(shm_area), 0666 | IPC_CREAT);
    shm_area *smem = (shm_area *)shmat(shmid, NULL, 0);

    puts("Enter String: ");
    fgets(smem->data, BUFFSIZE, stdin);
    smem->data[strcspn(smem->data, "\n")] = 0;

    sleep(5); 

    if (smem->result == 0) {
        puts("Not Palindrome");
    } else {
        puts("Palindrome");
    }

    shmdt(smem);
    return 0;
}
