#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//#define THREADS 8
short THREADS;
char CHUNK;

struct Stuff {
	int length;
	char* data;
	char* target;
	int tid;
};

void* string_search(void* stuff) {
	char* current;
	char* a;
	char* b;
	int* result = malloc(sizeof(int));
	char* data = ((struct Stuff*) stuff)->data;
	char* target = ((struct Stuff*) stuff)->target;
	int tid = ((struct Stuff*) stuff)->tid;
	int length = ((struct Stuff*) stuff)->length;

	int start = (length / THREADS) * tid;
	int end = start + (length / THREADS);

	if (tid == (THREADS - 1)) {
		end = length;
	}

	for (current = data + start; current != (data + end); current++) {
		if (*current == *target) {
			a = current + 1;
			b = target + 1;
			while(*b != '\0') {
				if (*a != *b) {
					break;
				}
				a++;
				b++;
			}
			if (*b == '\0') {
				*result = 1;
				return (void*) result;
			}
		}
	}

	*result = 0;
	return (void*) result;
}


int main(int argc, char** argv) {
	FILE* file;
	unsigned int length;
	char* data;
	char target[256];
	int found;
	time_t a, b;

	/* get start time */
	a = time(NULL);

	/* open the file */
	if (argc < 4) {
	//	printf("Please pass an input file.\n");
		printf("Please pass 4 arguments.\n");
		return 0;
	}
	file = fopen(argv[1], "r");
	if (!file) {
		printf("Could not open %s for reading.\n", argv[1]);
		return 0;
	}

	if(*argv[2] >= '0' && *argv[2] <= '9') {
		CHUNK = atoi(argv[2]);
		printf("chunk_size: %d\n", CHUNK);
	}
	else {
		CHUNK = *argv[2];
		printf("chunk_size: %c\n", CHUNK);
	}
	THREADS = atoi(argv[3]);
	printf("num_threads: %d\n", THREADS);

	/* find the length of the file */
	fseek(file, 0L, SEEK_END);
	length = ftell(file);
	fseek(file, 0L, SEEK_SET);

	/* read the file into memory */
	data = malloc(length * sizeof(char) + 1);
	memset(data, 0, length);
	fread(data, sizeof(char), length, file);

	b = time(NULL);
	double read = difftime(b, a);
	printf("Reading took %lf seconds.\n", read);

	/* ask what should be searched for */
	printf("Enter search term: ");
	scanf("%s", target);

	a = time(NULL);
	/* now do the searching */
	struct Stuff stuffs[THREADS];
	pthread_t threads[THREADS];

	int i;
	for (i = 0; i < THREADS; i++) {
		stuffs[i].tid = i;
		stuffs[i].length = length;
		stuffs[i].data = data;
		stuffs[i].target = target;

        pthread_create(&threads[i], NULL, &string_search, &stuffs[i]);
    }

	/* gather results */
	found = 0;
	for (i = 0; i < THREADS; i++) {
		int* local_result;
		pthread_join(threads[i], (void**) &local_result);

		if (*local_result) {
			found = 1;
		}

		free(local_result);
	}

	b = time(NULL);
	double search = difftime(b, a);
	printf("Searching took %lf seconds.\n", search);

	if (found) {
		printf("Found it!\n");
	} else {
		printf("Not found...\n");
	}

	return 0;
}

