#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define DATASIZE 50

int main(){
	int fd1=open("./myfifo1",O_RDONLY);
	char s3[DATASIZE],s4[DATASIZE];
	char *a="SAME";
	char *b="NOT SAME";
	read(fd1,s3,DATASIZE);
	read(fd1,s4,DATASIZE);
	mkfifo("./myfifo2",0666|O_CREAT);
	int fd2=open("./myfifo2",O_WRONLY);
	if (strcmp(s3,s4)==0)
		write(fd2,a,strlen(a)+1);
	else
		write(fd2,b,strlen(b)+1);


	close(fd1);
	return 0;
}
