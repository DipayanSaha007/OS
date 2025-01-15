#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

volatile sig_atomic_t signal_received = 0;

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        signal_received = 1; 
    }
}

int main() {
    pid_t pid;
    signal(SIGUSR1, sig_handler);

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        sleep(2); 
        printf("Child process (PID: %d) sending SIGUSR1 to parent process (PID: %d)\n", getpid(), getppid());
        kill(getppid(), SIGUSR1);  
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent process (PID: %d) created.\n", getpid());
        printf("Parent process will print messages until it receives SIGUSR1.\n");

        while (!signal_received) {
            puts("Parent waiting for signal...");
            sleep(1);
        }
        printf("Received SIGUSR1 signal from child process. Exiting...\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}

