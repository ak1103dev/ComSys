#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

int lines;
int id[100];

void run_cmd(char *cmd)
{
    pid_t pid;
    char *argv[] = {"sh", "-c", cmd, NULL};
    int status;
    status = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);
    if (status == 0) {
        if (waitpid(pid, &status, 0) != -1) {
        } else {
            perror("waitpid");
        }
    } else {
        printf("posix_spawn: %s\n", strerror(status));
    }
}

void readFile() {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	int ch = 0;
	lines = 0;

	fp = fopen("tmp", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int i = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		id[i] = atoi(line);
		i++;
	}
	lines = i;

	fclose(fp);
	if (line)
		free(line);

}

int main(int argc, char *argv[])
{
	run_cmd("ls -l | grep ^- | wc -l");
	//readFile();
    return 0;
}
