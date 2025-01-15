#include <stdio.h>
#include <pthread.h>
#define N 10
#define MAX 100

typedef struct {
	int upper,lower;
}args;

void *prime(void *a1) {
	args *a = (args *)a1;
	int l = a->lower;
	int u = a->upper;
	for(int i=l;i<=u;i++) {
		int flag = 0;
		for(int j=2;j<i/2;j++) {
			if(i%j == 0) 
				flag = 1;
				break;
		}
		if(flag == 0) {
			printf("%d ",i);
		}

	}

}

int main() {
	pthread_t thid[N];
	args a1;

	for(int i=0;i<N;i++) {
		a1.lower = (i*(MAX/N)) + 1;
		a1.upper = a1.lower + ((MAX/N)-1);
		pthread_create(&thid[i],NULL,prime,(void *)&a1);
	}
	for(int i=0;i<N;i++) {
		pthread_join(thid[i],NULL);
	}

	return 0;
}
