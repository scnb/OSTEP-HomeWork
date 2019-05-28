#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fp = open("test.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("child,file descriptor is: %d\n",fp);
		write(fp,"child",5);
	}
	else
	{
		printf("parent,file descriptor is: %d\n",fp);
		write(fp,"parent",6);
	}
	return 0;
}
