#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("hello\n");
	}
	else
	{
		waitpid(rc);
		printf("goodbye\n");
	}
	return 0;
}
