#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("I am child\n");
		close(STDOUT_FILENO);
		printf("I have closed standard output\n");
	}
	else 
	{
		printf("I am parent\n");
	}
	return 0;
}
