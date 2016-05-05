#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define NITER 1000000
#define THREADS 5

key_t key;
int shmid;
int *cnt;

sem_t count_sem;

void *Count(void *a)
{
    int i;
    for(i = 0; i < NITER; i++)
    {
		sem_wait(&count_sem);
		*cnt = *cnt + 1;
		sem_post(&count_sem);
    }
//    printf("segment contains: \"%d\"\n", *cnt);
}

void sharedMemory()
{

    // make the key:
    if ((key = ftok("file", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // connect to (and possibly create) the segment:
    if ((shmid = shmget(key, sizeof(pthread_t), 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach to the segment to get a pointer to it:
    cnt = shmat(shmid, (void *)0, 0);
    if (cnt == (int *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // read or modify the segment, based on the command line:
	*cnt = 0;
    printf("segment contains: \"%d\"\n", *cnt);

}

void dtachMemory() {
    // detach from the segment:
    if (shmdt(cnt) == -1) {
        perror("shmdt");
        exit(1);
    }
}


int main(int argc, char * argv[])
{
    pthread_t tid[THREADS];

	sharedMemory();

	int res = sem_init(&count_sem, 0, 1); // 0 is locked
	if(res < 0) {
		perror("Semaphore initialization failed");
		exit(0);
	}

	int i;

	for(i = 0; i < THREADS; i++) {
		if(pthread_create(&tid[i], NULL, Count, NULL))
		{
		  printf("\n ERROR creating thread %d", i+1);
		  exit(1);
		}
	}

	for(i = 0; i < THREADS; i++) {
		if(pthread_join(tid[i], NULL))	// wait for the thread i to finish
		{
		  printf("\n ERROR joining thread");
		  exit(1);
		}
	}

    if (*cnt < THREADS*NITER)
        printf("\n BOOM! cnt is [%d], should be %d\n", *cnt, THREADS*NITER);
    else
        printf("\n OK! cnt is [%d]\n", *cnt);

    pthread_exit(NULL);
	sem_destroy(&count_sem);
	dtachMemory();
}

