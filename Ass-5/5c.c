// .c to create a zombie process & verify the output with ps -f command

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pid;
	puts("Starting Parent\n");
	pid = fork();
	if (pid > 0) {
		printf("Parent: PID = %d\tPPID = %d\n",getpid(),getppid());
		sleep(15);
		int stat;
		wait(&stat);
	}
	if (pid == 0) {
		printf("Child: PID = %d\tPPID = %d\n",getpid(),getppid());
		sleep(8);
		puts("Child Died");
	}
	return 0;
}
