#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int x = 0;
	x = 100;
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("child: x = %d\n", x);
		x = 10;
		printf("child: after change: x = %d\n",x);
	}
	else
	{
		printf("parent: x = %d\n",x);
		x = 20;
		printf("parent: after change: x = %d\n",x);
	}
	return 0;
}
