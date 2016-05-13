#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define WRFLAGS (O_WRONLY | O_CREAT | O_TRUNC)
#define MODE600 (S_IRUSR | S_IWUSR)

void main() {
  	close (0);			// close standard input
  	if (open("pipe1.c", O_RDONLY) == -1) printf ("open input file failed\n");
  	close (1);			// close standard output
  	if (open("file2", WRFLAGS, MODE600) == -1) printf("open output failed\n");
  	execlp ("cat", "cat", 0);	// execute cat command
  	printf ("failed to execute ‘cat’\n");
  	execlp ("grep ant", "grep ant", 0);	// execute cat command
  	printf ("failed to execute ‘grep’\n");
}
