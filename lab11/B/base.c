#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int string_search(char* data, char* target) {
	char* current;
	char* a;
	char* b;

	for (current = data; *current != '\0'; current++) {
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
				return 1;
			}
		}
	}

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
  if (argc < 2) {
    printf("Please pass an input file.\n");
    return 0;
  }
  file = fopen(argv[1], "r");
  if (!file) {
    printf("Could not open %s for reading.\n", argv[1]);
    return 0;
  }

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
  found = string_search(data, target);
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

