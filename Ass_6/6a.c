#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define SIZE 50

int main(){
	int pfd[2];
	pipe(pfd);
	int pid=fork();
	if(pid>0){
		char data2[SIZE];
		read(pfd[0],data2,SIZE);
		printf("Parent process (PID = %d):\nMessage is: ",getpid());
		puts(data2);
	}
	if(pid==0){
		char data1[SIZE];
		printf("Child process (PID = %d):\nEnter a message: ",getpid());
		fgets(data1,SIZE,stdin);
		write(pfd[1],data1,strlen(data1)+1);
	}
	return 0;
}
