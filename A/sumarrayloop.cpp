#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

#define NTHREADS      4
#define ARRAYSIZE 1000000000
//#define ARRAYSIZE 4
#define ITERATIONS   ARRAYSIZE / NTHREADS

unsigned long long sum=0;
unsigned int a[ARRAYSIZE];
int len;
pthread_mutex_t sum_mutex;

void read_file(char *argv[]) {
	int i = 0;
	fstream myfile(argv[1], std::ios_base::in);
	myfile >> len;
	while (myfile >> a[i++]);
}

void *do_work(void *tid)
{
	unsigned int i, start, *mytid, end;
	//double mysum=0.0;
	unsigned long long mysum = 0;

	// Initialize my part of the global array and keep local sum
	mytid = (unsigned int *) tid;
	start = (*mytid * ITERATIONS);
	end = start + ITERATIONS;
	printf ("Thread %d doing iterations %d to %d\n",*mytid,start,end-1);
	for (i=start; i < end ; i++) {
	//a[i] = i * 1.0;
		mysum = mysum + a[i];
	}

	// Lock the mutex and update the global sum, then exit
	pthread_mutex_lock (&sum_mutex);
	sum = sum + mysum;
	pthread_mutex_unlock (&sum_mutex);
	pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
	time_t start, finish;
	cout << "ARGC: " << argc << endl;
	if (argc < 2) {
		return 0;
	}
	read_file(argv);
	unsigned int i, tids[NTHREADS];
	pthread_t threads[NTHREADS];
	pthread_attr_t attr;

  // Pthreads setup: initialize mutex and explicitly create threads in a joinable state (for portability).  Pass each thread its loop offset
	start = time(NULL);

	pthread_mutex_init(&sum_mutex, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (i=0; i<NTHREADS; i++) {
		tids[i] = i;
		pthread_create(&threads[i], &attr, do_work, (void *) &tids[i]);
	}

  // Wait for all threads to complete then print global sum
	for (i=0; i<NTHREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	printf ("Done. Sum= %lld \n", sum);


  // Clean up and exit
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&sum_mutex);
	finish = time(NULL);
	printf("time = %ld\n", finish - start);
	pthread_exit (NULL);

}

