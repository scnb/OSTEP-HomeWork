#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit (1);
	}
	else if (rc == 0)
	{
		printf("I am child\n");
		char *myargs[2];
		myargs[0] = "/bin/ls";
		myargs[1] = NULL;
		//1.
	//	execvp(myargs[0],myargs);
		//2.
   //   execl("/bin/ls","ls",NULL);
		//3.
   //	execlp("/bin/ls","ls",NULL);
		//4.
		execv(myargs[0],myargs);
	}
	else
	{
		printf("I am parent\n");
	}
	return 0;
}

