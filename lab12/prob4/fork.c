#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pid_t pid;

void *mythread(void *arg) {
	int *data = (int *) arg;
	*data = *data + 1;
	printf("Data is %d, Pid is %d\n", *data, pid);
	pthread_exit(0);
}

int foo;

#define N 100

void test() {
	pthread_t t1;
	foo = 0;
	int i;
	int status;
	for (i=0; i < N; i++)
	{
		if (i %2 ==0 ) {
			pid = fork();
			pthread_create(&t1, NULL, &mythread, &foo);
			pthread_join(t1, NULL);
			wait(&status);
		}
		if (pid == 0 ) {
			pthread_create(&t1, NULL, &mythread, &foo);
			pthread_join(t1, NULL);
			exit(1);
		}
	}
}

void main() {
	/*
 	pid = fork();
	if (pid == 0) {
		pthread_create(&t1, NULL, &mythread, &foo);
		pthread_join(t1, NULL);
	}
	else {
	}
	*/
	test();
}
