#include <unistd.h>
#include <stdio.h>

void main() {
	int fda[2];	// file descriptors
	if ( pipe(fda) < 0 )
		printf("create pipe failed\n");

	switch ( fork() ) {	// fork an identical sub-process
		case -1 : printf("fork failed\n");
		case 0:	// run ls in child process
			close (1);						// close standard output
			dup ( fda[1] );					// duplicate pipe write end
			close ( fda[1] );				// close pipe write end
			close ( fda[0] );				// close pipe read end
			printf("in child\n");
			execlp ("ls", "ls", 0);			// execute ls command
			printf ("failed to exec ls\n");	// should not get here
			break;
		default:	// run wc in parent
			close (0);						// close standard input
			dup (fda[0] );					// duplicate pipe read end
			close ( fda[0] );				// close read end of pipe
			close (fda[1] );					// close write end of pipe
			execlp ("wc", "wc", "-w", 0);	// execute wc command
			printf ("failed to execute4 wc\n");
			break;
	}
}