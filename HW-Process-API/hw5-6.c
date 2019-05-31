#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit (1);
	}
	else if (rc == 0)
	{
		printf("I am child, (pid:%d)\n",(int)getpid());
	}
	else 
	{
		int rc_wait = waitpid(rc,NULL,WUNTRACED);
		printf("I am parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, (int)getpid());
	}
	return 0;
}
