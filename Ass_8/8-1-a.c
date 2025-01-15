#include <stdio.h>
#include <pthread.h>

int n = 10;
int sum = 0;

void *th_func(void *arg) {
	for(int i=1;i<=n;i++) {
		sum = sum + i;
	}
	printf("The sum of %d natural numbers is : %d\n",n,sum);
	pthread_exit(NULL);
}

int main() {
	puts("Main thread started...\n");
	pthread_t th;
	pthread_create(&th,NULL,th_func,NULL);
	pthread_join(th,NULL);
	return 0;
}
