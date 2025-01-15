#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum){
	signal(SIGINT,SIG_DFL);
	printf("\nSignal Number = %d\n",signum);
}

int main(){
	signal(SIGINT,sig_handler);
	for (int i=1;;i++){
		puts("Signal Handler\n");
		sleep(1);
	}
	return 0;
}
