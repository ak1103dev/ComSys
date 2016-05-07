#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 100

pid_t pid;

void *mythread(void *arg) {
	int *data = (int *) arg;
	*data = *data + 1;
	printf("Data is %d, Pid is %d\n", *data, pid);
	pthread_exit(0);
}

int foo;

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
			exit(0);
		}
	}
}

void main() {
	test();
}
