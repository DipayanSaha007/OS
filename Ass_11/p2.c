#include <stdio.h>
#include "header.h"
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
    int shmid = shmget(1234, sizeof(shm_area), 0666 | IPC_CREAT);
    shm_area *smem = (shm_area *)shmat(shmid, NULL, 0);

    smem_init(smem);
    sleep(5);

    char str[BUFFSIZE];
    strcpy(str, smem->data);
    int n = strlen(str);
    int flag = 1; 

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            flag = 0;
            break; 
        }
    }

    smem->result = flag;

    shmdt(smem);
    return 0;
}
