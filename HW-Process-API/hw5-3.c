#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int rc = fork();
	int fp = open("ok.test",O_CREAT|O_RDWR,S_IRWXU);
	if (rc < 0)
	{
		fprintf(stderr,"fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("hello\n");
		write(fp,"ok",2);
	}
	else
	{
		char str[2];
		read(fp,str,2);
		while (strcmp(str,"ok")!=0)
		{
			read(fp,str,2);
		}
		printf("goodbye\n");
	}
	return 0;
}
