// .c to create orphan process & chect outputs with ps-f command

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int pid;
	puts("Starting Parent\n");
	pid = fork();
	if (pid > 0) {
		printf("Parent: PID = %d\tPPID = %d\n",getpid(),getppid());
		sleep(8);
		puts("Parent Died, Child is an Orphan");
	}
	if (pid == 0) {
		printf("Child: PID = %d\tPPID = %d\n",getpid(),getppid());
		sleep(15);
	}
	return 0;
}
