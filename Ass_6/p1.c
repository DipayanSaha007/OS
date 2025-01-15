#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define DATASIZE 50

int main(){
	char s1[DATASIZE],s2[DATASIZE],m[DATASIZE];
	printf("Enter the first string: ");
	fgets(s1,DATASIZE,stdin);
	printf("Enter the second string: ");
	fgets(s2,DATASIZE,stdin);
	mkfifo("./myfifo1",0666|O_CREAT);
	int fd1=open("./myfifo1",O_WRONLY);
	write(fd1,s1,strlen(s1)+1);
	write(fd1,s2,strlen(s2)+1);
	int fd2=open("./myfifo2",O_RDONLY);
	read(fd2,m,DATASIZE);
	puts(m);
	close(fd2);
	return 0;
}
