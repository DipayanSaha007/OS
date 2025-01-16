// .c to create child process & print pid & ppid of parent and child

#include <stdio.h>
#include <unistd.h>

int main() {
	int pid; 
	puts("Starting Parent");
	pid = fork();
	if (pid > 0) {
		printf("Parent Process: PID = %d\tPPID = %d.\n",getpid(),getppid());
		sleep(1);
	}
	if (pid == 0) {
		printf("Child Process: PID = %d\tPPID = %d.\n",getpid(),getppid());
		sleep(1);
	}
	return 0;
}
