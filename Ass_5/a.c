#include<stdio.h>
#include<unistd.h>

int main(){
	int pid;
	puts("Starting Parent\n");
	pid=fork();
	if (pid>0){
		printf("Parent: PID = %d\tPPID = %d\n",getpid(),getppid());
		sleep(9);
	}
	if (pid==0){
		printf("Child: PID = %d\tPPID = %d\n",getpid(),getppid());
                sleep(9);
	}
	return 0;
}
