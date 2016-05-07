#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
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

void printChild() {
	int i = 0;
	for(i = 0; i < lines; i++) {
		printf("%d ", id[i]);
	}
}

int send_signal (int pid, char *a)
{
	int ret;
	ret = kill(pid,SIGKILL);
	printf("%s ", a);
	if(lines > 0) {
		printf("and its children ");
		printChild();
	}
	if(ret == 0) {
		printf("are killed.\n");
	}
	else {
		printf("exist before killing.\n");
	}

}

int main(int argc, char *argv[])
{
	char accept[5];
	char command[30] = "pgrep -P ";
	printf("Are you sure to kill %s and its children? ", argv[1]);
	scanf("%s", accept);
	if(strcmp(accept, "yes") == 0) {
		strcat(command, argv[1]);
		strcat(command, " > tmp");
		run_cmd(command);
		readFile();
		send_signal(atoi(argv[1]), argv[1]);
	}
    return 0;
}
