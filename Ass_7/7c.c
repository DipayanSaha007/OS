#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int year;

int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        if (is_leap_year(year)) {
            printf("Year %d is a leap year.\n", year);
        } else {
            printf("Year %d is not a leap year.\n", year);
        }
    }
}

int main() {
    pid_t pid;
    printf("Enter a year: ");
    scanf("%d", &year);
    signal(SIGUSR1, sig_handler);

    if ((pid = fork()) == 0) {
        while (1) {
            pause(); 
        }
    } else if (pid > 0) {
        while (1) {
            sleep(5);
            kill(pid, SIGUSR1); 
        }
    } else {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

