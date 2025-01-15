#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 

void  *th_func(void *n) {
	int x = *((int *)n);
	int *res = (int *)malloc(sizeof(int));
	int sum = 0;
	for(int i=1;i<=x;i++) {
		sum = sum + i;
	}
	*res = sum;
	pthread_exit((void *)res);
}

int main() {
	puts("Main thread started...\n");
	int n;
	int *ret;
	printf("Enter the no. of natural numbers: ");
	scanf("%d",&n);
	pthread_t th1;
	pthread_create(&th1,NULL,th_func,(void *)&n);
	pthread_join(th1,(void **)&ret);
	printf("Sum = %d\n",*ret);
	return 0;
}
